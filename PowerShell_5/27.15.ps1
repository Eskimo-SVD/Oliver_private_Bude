function New-CMSTestCert
{
  param
  (
    [SecureString]
    [Parameter(Mandatory=$true)]
    $Password,

    $FriendlyName = 'CMS Test Cert',

    $CN = 'CMSTestCert',

    $OutputPath = "$env:temp\CMSTestCertificate",

    $ValidUntil = (Get-Date).AddYears(5)
  )

  # Zertifikat im User-Store ablegen:
  $cert = New-SelfSignedCertificate -KeyUsage DataEncipherment, KeyEncipherment -KeySpec KeyExchange -FriendlyName $FriendlyName -Subject "CN=$CN" -KeyExportPolicy ExportableEncrypted -CertStoreLocation Cert:\CurrentUser\My -NotAfter $ValidUntil -TextExtension @('2.5.29.37={text}1.3.6.1.4.1.311.80.1')
  
  # �ffentlichen Teil als cert-Datei exportieren:
  if (!(Test-Path -Path $OutputPath)) { $null = New-Item -Path $outputPath -ItemType Directory -Force }
  $pathCer = Join-Path -Path $OutputPath -ChildPath "$CN.cer"
  $null = Export-Certificate -Type CERT -FilePath $pathCer -Cert $cert -Force
  
  # privaten Teil als pfx-Datei exportieren:
  $pathPfx = Join-Path -Path $OutputPath -ChildPath "$CN.pfx"
  $null = $cert | Export-PfxCertificate -Password $Password -FilePath $pathPfx 

  # Zertifikat aus Zertifikat-Speicher l�schen:
  $cert | Remove-Item
  Get-Item Cert:\CurrentUser\CA\$($cert.Thumbprint) | Remove-Item

  # Ergebnis anzeigen
  explorer $OutputPath
}
