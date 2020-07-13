function Get-CodesigningCertificate
{
  param
  (
    $titel = 'Verfügbare Identitäten',

    $text = 'Bitte Zertifikat für Signatur auswählen'
  )

  # Zertifikate ermitteln:
  # hier anpassen und mit Where-Object ergänzen,
  # falls nur bestimmte Zertifikate angezeigt werden sollen:
  $zertifikate = Get-ChildItem cert:\currentuser\my -Codesigning

  # Zertifikatcontainer beschaffen und füllen:
  Add-Type -AssemblyName System.Security
  $container = New-Object System.Security.Cryptography.X509Certificates.X509Certificate2Collection
  $container.AddRange($zertifikate)

  # Auswahlfeld anzeigen:
  [System.Security.Cryptography.x509Certificates.X509Certificate2UI]::SelectFromCollection($container, $titel, $text, 0)
}
