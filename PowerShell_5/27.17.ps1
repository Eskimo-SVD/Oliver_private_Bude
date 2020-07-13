#Requires -RunAsAdministrator

function New-DSCTestCert
{
  param
  (
    [SecureString]
    [Parameter(Mandatory=$true)]
    $Password,

    $FriendlyName = 'DSC Test Cert',

    $CN = 'DSCTestCert',

    $OutputPath = "$env:temp\DSCTestCertificate",

    $ValidUntil = (Get-Date).AddYears(5)
  )

  # Zertifikat im User-Store ablegen:
  $cert = New-SelfSignedCertificate -KeyUsage DataEncipherment, KeyEncipherment -KeySpec KeyExchange -FriendlyName $FriendlyName -Subject "CN=$CN" -KeyExportPolicy ExportableEncrypted -CertStoreLocation Cert:\LocalMachine\My -NotAfter $ValidUntil -TextExtension @('2.5.29.37={text}1.3.6.1.4.1.311.80.1')
  
  # öffentlichen Teil als cert-Datei exportieren:
  if (!(Test-Path -Path $OutputPath)) { $null = New-Item -Path $outputPath -ItemType Directory -Force }
  $pathCer = Join-Path -Path $OutputPath -ChildPath "$CN.cert"
  $null = Export-Certificate -Type CERT -FilePath $pathCer -Cert $cert -Force
  
  # privaten Teil als pfx-Datei exportieren:
  $pathPfx = Join-Path -Path $OutputPath -ChildPath "$CN.pfx"
  $null = $cert | Export-PfxCertificate -Password $Password -FilePath $pathPfx 

  # Zertifikat aus Liste der Zwischenzertifizierungsstellen löschen:
  Get-Item Cert:\CurrentUser\CA\$($cert.Thumbprint) | Remove-Item

  # Ergebnis anzeigen
  explorer $OutputPath
  
  # Zertifikatinfos zurückgeben
  $thumbprint = $cert.Thumbprint
  "Thumbprint =      '$thumbprint'"
  "CertificateFile = '$pathCer'"
}
