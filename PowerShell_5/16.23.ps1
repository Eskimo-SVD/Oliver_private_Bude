function Test-ParameterDynamicNeu
{
  [CmdletBinding()]
  param
  (
    [Parameter(Mandatory=$true)]
    [ValidateSet('ChangeLocation','ChangeSomethingElse')]
    $Mode
  )

  dynamicparam
  {
    $Eimer = New-Object -TypeName System.Management.Automation.RuntimeDefinedParameterDictionary

    # dynamische Parameter nur anzeigen, wenn in -Mode der Wert 'ChangeLocation' gewählt wurde:
    if ($Mode -eq 'ChangeLocation')
    {
  
      $ListeAttribute = New-Object -TypeName System.Collections.ObjectModel.Collection[System.Attribute]	
      $AttribParameter = New-Object System.Management.Automation.ParameterAttribute
      $AttribParameter.Mandatory = $true
      $ListeAttribute.Add($AttribParameter)
      $Parameter = New-Object -TypeName System.Management.Automation.RuntimeDefinedParameter('ID',[Int], $ListeAttribute)
      $Eimer.Add('ID', $Parameter)

      $ListeAttribute = New-Object -TypeName System.Collections.ObjectModel.Collection[System.Attribute]	
      $AttribParameter = New-Object System.Management.Automation.ParameterAttribute
      $AttribParameter.Mandatory = $false
      $ListeAttribute.Add($AttribParameter)

      $Werte = 'NewYork','Cork','Hannover'
      $AttribValidateSet = New-Object System.Management.Automation.ValidateSetAttribute($Werte)
      $ListeAttribute.Add($AttribValidateSet)

      $Parameter = New-Object -TypeName System.Management.Automation.RuntimeDefinedParameter('City',[String], $ListeAttribute)
      $Eimer.Add('City', $Parameter)
    }
    $Eimer
  }
  

  end
  {
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
