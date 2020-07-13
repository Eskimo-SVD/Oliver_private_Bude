# Achtung: benötigt die Funktion New-SelfsignedCertificateEx 
# Bezugsquelle: https://gallery.technet.microsoft.com/scriptcenter/Self-signed-certificate-5920a7c6

$Path = "$env:temp\zertifikat.pfx"
$Password = Read-Host -Prompt 'Kennwort für Zertifikat' -AsSecureString

New-SelfsignedCertificateEx -Exportable  -Path $path -Password $password -Subject 'CN=Sicherheitsabteilung' -EKU '1.3.6.1.5.5.7.3.3' -KeySpec 'Signature' -KeyUsage 'DigitalSignature' -FriendlyName 'IT Sicherheit' -NotAfter (Get-Date).AddYears(5)
