# Pfad zum Desktop
$Path = "$HOME\Desktop"

# unterschiedliche Ausgabe im Vergleich
$FilePath1 = Join-Path -Path $Path -ChildPath 'OutFile.txt'
$FilePath2 = Join-Path -Path $Path -ChildPath 'SetContent.txt'
$FilePath3 = Join-Path -Path $Path -ChildPath 'OutStringSetContent.txt'

$daten = Get-EventLog -LogName System -EntryType Error, Warning -Newest 20 

$daten | Out-File -FilePath $FilePath1
$daten | Set-Content -Path $FilePath2
$daten | Out-String | Set-Content -Path $FilePath3 -Encoding Unicode

notepad.exe $FilePath1
notepad.exe $FilePath2
notepad.exe $FilePath3
