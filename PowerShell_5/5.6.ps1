# Zertifikat aus pfx-Datei laden
$path = "$env:temp\zertifikat.pfx"
$cert = Get-PfxCertificate -FilePath $Path

$cert
