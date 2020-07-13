# gesamten Inhalt des Zertifikatspeichers auslesen
Get-ChildItem cert:\ -Recurse | 
# nur Zertifikate berücksichtigen 
Where-Object { 
  $_ -is [System.Security.Cryptography.X509Certificates.X509Certificate2] 
} | 
# nur abgelaufene Zertifikate
Where-Object {
  $_.NotAfter -lt (Get-Date)
} |
# nur Name und Ablaufdatum anzeigen
Select-Object -Property FriendlyName, NotAfter, Subject |
Out-GridView -Title 'Abgelaufene Zertifikate'
