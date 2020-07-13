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
    # wenn bereits mit -Firma eine Firma ausgew�hlt wurde

    # hier stehen f�r jede Firma die g�ltigen Werte, die f�r
    # -Abteilung angegeben werden d�rfen:
    $data = @{
      FirmaA = 'Gesch�ftsf�hrung', 'Marketing', 'Vertrieb'
      FirmaB = 'Marketing', 'Vertrieb'
      FirmaC = 'Gesch�ftsf�hrung', 'Au�endienst', 'Fuhrpark'
      FirmaD = 'Gesch�ftsf�hrung', 'Geb�udemanagement', 'Fuhrpark'
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

      # g�ltige Werte festsetzen;
      # die g�ltigen Abteilungsnamen f�r eine Firma stehen im Hashtable $data
      # $data.$firma liefert also die Liste der f�r die jeweilige Firma g�ltigen
      # Abteilungsnamen.
      # Diese werden als ValidateSet dynamisch dem Parameter hinzugef�gt:
      $attribute = New-Object System.Management.Automation.ValidateSetAttribute($data.$firma)
      $attributeCollection.Add($attribute)

      # dynamischen Parameter -Abteilung anlegen:
      $Name = 'Abteilung'
      $dynParam = New-Object -TypeName System.Management.Automation.RuntimeDefinedParameter($Name,
        [string], $attributeCollection)
      $paramDictionary.Add($Name, $dynParam)

      # Parameter zur�ckgeben:
      $paramDictionary
    }
  }

  end
  {
    'Die �bergebenen Parameter:'
    $PSBoundParameters
  }
}
