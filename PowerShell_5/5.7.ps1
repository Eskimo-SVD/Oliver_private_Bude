function Get-CodesigningCertificate
{
  param
  (
    $titel = 'Verf�gbare Identit�ten',

    $text = 'Bitte Zertifikat f�r Signatur ausw�hlen'
  )

  # Zertifikate ermitteln:
  # hier anpassen und mit Where-Object erg�nzen,
  # falls nur bestimmte Zertifikate angezeigt werden sollen:
  $zertifikate = Get-ChildItem cert:\currentuser\my -Codesigning

  # Zertifikatcontainer beschaffen und f�llen:
  Add-Type -AssemblyName System.Security
  $container = New-Object System.Security.Cryptography.X509Certificates.X509Certificate2Collection
  $container.AddRange($zertifikate)

  # Auswahlfeld anzeigen:
  [System.Security.Cryptography.x509Certificates.X509Certificate2UI]::SelectFromCollection($container, $titel, $text, 0)
}
