function Test-DynamicParameter
{
  [CmdletBinding()]

  param
  (
    [Parameter(Mandatory=$true)]
    [ValidateSet('FirmaA','FirmaB','FirmaC','FirmaD')]
    # Name der Firma, erlaubt sind nur die im ValidateSet angegebenen
    # Firmennamen 'FirmaA','FirmaB','FirmaC' und 'FirmaD'
    $Firma
  )

  dynamicparam
  {
    # der zweite (dynamische) Parameter -Abteilung wird nur eingeblendet,
    # wenn bereits mit -Firma eine Firma ausgewählt wurde

    # hier stehen für jede Firma die gültigen Werte, die für
    # -Abteilung angegeben werden dürfen:
    $data = @{
      FirmaA = 'Geschäftsführung', 'Marketing', 'Vertrieb'
      FirmaB = 'Marketing', 'Vertrieb'
      FirmaC = 'Geschäftsführung', 'Außendienst', 'Fuhrpark'
      FirmaD = 'Geschäftsführung', 'Gebäudemanagement', 'Fuhrpark'
    }

    # wurde bereits die Firma mit -Firma angegeben?
    if ($Firma)
    {
      # ja, also dynamischen Parameter anlegen:
      $paramDictionary = New-Object -TypeName System.Management.Automation.RuntimeDefinedParameterDictionary
      $attributeCollection = New-Object -TypeName System.Collections.ObjectModel.Collection[System.Attribute]

      # Parameter-Attribute festsetzen:
      $attribute = New-Object System.Management.Automation.ParameterAttribute
      $attribute.ParameterSetName = '__AllParameterSets'
      $attribute.Mandatory = $false
      $attributeCollection.Add($attribute)

      # gültige Werte festsetzen;
      # die gültigen Abteilungsnamen für eine Firma stehen im Hashtable $data
      # $data.$firma liefert also die Liste der für die jeweilige Firma gültigen
      # Abteilungsnamen.
      # Diese werden als ValidateSet dynamisch dem Parameter hinzugefügt:
      $attribute = New-Object System.Management.Automation.ValidateSetAttribute($data.$firma)
      $attributeCollection.Add($attribute)

      # dynamischen Parameter -Abteilung anlegen:
      $Name = 'Abteilung'
      $dynParam = New-Object -TypeName System.Management.Automation.RuntimeDefinedParameter($Name,
        [string], $attributeCollection)
      $paramDictionary.Add($Name, $dynParam)

      # Parameter zurückgeben:
      $paramDictionary
    }
  }

  end
  {
    'Die übergebenen Parameter:'
    $PSBoundParameters
  }
}
