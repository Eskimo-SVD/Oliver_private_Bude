function New-NetObject
{
  [CmdletBinding()]
  param
  (
    [type]
    $TypeName
  )

  dynamicparam
  {
    if (-not ($TypeName.IsClass -and !$TypeName.GetConstructor([Type]::EmptyTypes)))
    {
      $paramDictionary = New-Object -TypeName System.Management.Automation.RuntimeDefinedParameterDictionary
      $Properties = $TypeName.GetProperties() | Where-Object CanWrite

      foreach ($Property in $Properties)
      {
        $attributes = New-Object System.Management.Automation.ParameterAttribute
        $attributes.ParameterSetName = '__AllParameterSets'
        $attributes.Mandatory = $false
        $attributeCollection =
          New-Object -TypeName System.Collections.ObjectModel.Collection[System.Attribute]
        $attributeCollection.Add($attributes)
        $dynParam1 = New-Object -TypeName System.Management.Automation.RuntimeDefinedParameter($Property.Name,
         $Property.PropertyType, $attributeCollection)
        $paramDictionary.Add($Property.Name, $dynParam1)
      }

      $paramDictionary
    }
  }

  end
  {
    $null = $PSBoundParameters.Remove('TypeName')
    $PSBoundParameters -as $TypeName
  }
}
