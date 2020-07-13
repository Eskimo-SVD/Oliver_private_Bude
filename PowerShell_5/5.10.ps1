# Liste der Thumbprints von vertrauenswürdigen Zertifikaten:
$WhiteList = @('D10858D99CD176979DF793E4AD37A5639CB8D9D5', '6262A18EC19996DD521F7BDEAA0E079544B84241')

# Alle PowerShell Skripts im Benutzerprofil finden...
Get-ChildItem -Path $HOME -Filter *.ps1 -Include *.ps1 -Recurse -ErrorAction SilentlyContinue  |
  # zu kleine Dateien ausschließen (Signaturen erfordern Mindestlänge)
  Where-Object { $_.Length -gt 10 } |
  # Signatur lesen
  Get-AuthenticodeSignature |
  # nur ungültige Signaturen anzeigen
  Where-Object { 
    $ok = ($_.Status -eq 'Valid') -or ($_.Status -eq 'UnknownError' -and $WhiteList -contains $_.SignerCertificate.Thumbprint) 
    !$ok
  } |
  Select-Object -Property Path, Status, StatusMessage |
  Out-GridView
