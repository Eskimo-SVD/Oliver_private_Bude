function Test-ParameterDynamic
{
  # Cmdletbinding und param() zwingend nötig
  [CmdletBinding()]
  param()

  # definiert die dynamischen Parameter:
  dynamicparam
  {
    # der "Eimer" sammelt alle dynamischen Parameter und wird
    # am Ende zurückgegeben:
    $Eimer = New-Object -TypeName System.Management.Automation.RuntimeDefinedParameterDictionary

    # 1. Parameter definieren
    # eine Liste für die Attribute anlegen:
    $ListeAttribute = New-Object -TypeName System.Collections.ObjectModel.Collection[System.Attribute]	
    # [Parameter()]-Attribut definieren:
    $AttribParameter = New-Object System.Management.Automation.ParameterAttribute
    $AttribParameter.Mandatory = $true
    # der Attributliste hinzufügen:
    $ListeAttribute.Add($AttribParameter)
    # neuen Parameter mit Name, Typ und Attributen definieren:
    $Parameter = New-Object -TypeName System.Management.Automation.RuntimeDefinedParameter('ID',[Int], $ListeAttribute)
    # in den "Eimer" legen:
    $Eimer.Add('ID', $Parameter)

    # 2. Parameter definieren:
    $ListeAttribute = New-Object -TypeName System.Collections.ObjectModel.Collection[System.Attribute]	
    $AttribParameter = New-Object System.Management.Automation.ParameterAttribute
    $AttribParameter.Mandatory = $false
    $ListeAttribute.Add($AttribParameter)

    # ein zusätzliches [ValidateSet()] Attribut hinzufügen:
    $Werte = 'NewYork','Cork','Hannover'
    $AttribValidateSet = New-Object System.Management.Automation.ValidateSetAttribute($Werte)
    $ListeAttribute.Add($AttribValidateSet)

    $Parameter = New-Object -TypeName System.Management.Automation.RuntimeDefinedParameter('City',[String], $ListeAttribute)
    $Eimer.Add('City', $Parameter)

    # die beiden dynamischen Parameter zurückgeben:
    $Eimer
  }

  end
  {
    # automatisch alle Werte von verwendeten
    # dynamischen Parametern in Variablen speichern:
    foreach($key in $PSBoundParameters.Keys)
    {
      if ($MyInvocation.MyCommand.Parameters.$key.isDynamic)
      {
        Set-Variable -Name $key -Value $PSBoundParameters.$key
      }
    }
    
    "ID ist $ID und Stadt ist $City"
  }
}
