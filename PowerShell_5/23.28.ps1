# neuen lokalen Ordner anlegen:
New-Item -Path c:\daten -ItemType Directory | Out-Null

$session = New-PSSession -ComputerName server02
Copy-Item -Path C:\protokolle -Destination c:\daten -FromSession $session -Recurse
