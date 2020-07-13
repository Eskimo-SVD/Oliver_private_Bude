#requires -Version 5

$Path = "$env:temp\zertifikat.pfx"
$Password = Read-Host -Prompt 'Kennwort für Zertifikat' -AsSecureString

# Zertifikat anlegen:
$cert = New-SelfSignedCertificate -KeyUsage DigitalSignature -KeySpec Signature -FriendlyName 'IT Sicherheit' -Subject CN=Sicherheitsabteilung -KeyExportPolicy ExportableEncrypted -CertStoreLocation Cert:\CurrentUser\My -NotAfter (Get-Date).AddYears(5) -TextExtension @('2.5.29.37={text}1.3.6.1.5.5.7.3.3')

# Zertifikat in Datei exportieren:
$cert | Export-PfxCertificate -Password $Password -FilePath $Path 

# Zertifikat aus Speicher löschen:
$cert | Remove-Item
