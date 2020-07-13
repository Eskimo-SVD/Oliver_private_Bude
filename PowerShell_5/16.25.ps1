function ConvertTo-Euro
{
  [CmdletBinding()]
  param(
    # der Betrag der Fremdwährung
    [Parameter(Mandatory=$true, ValueFromPipeline=$true)]
    [Double]
    $Value
  )

  dynamicparam
  {
    $Eimer = New-Object -TypeName System.Management.Automation.RuntimeDefinedParameterDictionary

    # zwingenden Parameter "Currency" hinzufügen, der die Umrechungswährungen
    # der EZB enthält:
    $ListeAttribute = New-Object -TypeName System.Collections.ObjectModel.Collection[System.Attribute]	
    $AttribParameter = New-Object System.Management.Automation.ParameterAttribute
    $AttribParameter.Mandatory = $true
    $ListeAttribute.Add($AttribParameter)
    
    # gibt es noch keine Währungsliste?
    if ($script:currencies -eq $null)
    {
      # dann aus dem Internet abrufen:
      # dazu als Warnung einmal piepen:
      [Console]::Beep()
      
      $url = 'http://www.ecb.europa.eu/stats/eurofxref/eurofxref-daily.xml'
      $result = Invoke-RestMethod  -Uri $url
      # Währungsliste in scriptglobaler Variable speichern
      $script:currencies = $result.Envelope.Cube.Cube.Cube.currency
    }
    
    # ValidateSet mit den verfügbaren Währungen hinzufügen:
    # (die Währungen werden jetzt aus der gepufferten skriptglobalen
    # Variable verwendet und NICHT jedes Mal neu von der EZB abgerufen)
    $AttribValidateSet = New-Object System.Management.Automation.ValidateSetAttribute($script:currencies)
    $ListeAttribute.Add($AttribValidateSet)

    $Parameter = New-Object -TypeName System.Management.Automation.RuntimeDefinedParameter('Currency',[String], $ListeAttribute)
    $Eimer.Add('Currency', $Parameter)

    # dynamischen Parameter zurückgeben:
    $Eimer
  }

  # nur EINMAL die aktuellen Wechselkurse am Anfang der Pipeline
  # abrufen und dynamische Parameter in Variablen speichern (begin-Block):
  begin
  {
    # alle dynamischen Parameter in entsprechende
    # Variablen speichern
    foreach($key in $PSBoundParameters.Keys)
    {
      if ($MyInvocation.MyCommand.Parameters.$key.isDynamic)
      {
        Set-Variable -Name $key -Value $PSBoundParameters.$key
      }
    }
  
    # aktuellen Wechselkurs abrufen:
    $url = 'http://www.ecb.europa.eu/stats/eurofxref/eurofxref-daily.xml'
    $rates = Invoke-RestMethod  -Uri $url
    $rate = $rates.Envelope.Cube.Cube.Cube | 
    Where-Object { $_.currency -eq $Currency} |
    Select-Object -ExpandProperty Rate
  }

  # für JEDES über die Pipeline empfangene Objekt die
  # Berechnung durchführen:
  process
  {
    $result = [Ordered]@{
      Value = $Value
      Currency = $Currency
      Rate = $rate
      Euro = ($Value / $rate)
      Date = Get-Date
    }
    
    # Informationen als Objekt zurückgeben:
    New-Object -TypeName PSObject -Property $result
  }
}
