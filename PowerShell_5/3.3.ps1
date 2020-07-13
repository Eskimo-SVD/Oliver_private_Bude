# Pfad zum Desktop
$Path = "$HOME\Desktop"

# Datei mit den neuesten 20 kritischen System-Events erstellen
$FilePath = Join-Path -Path $Path -ChildPath 'FehlerEvents.txt'
Get-EventLog -LogName System -EntryType Error, Warning -Newest 20 | 
    Format-Table -AutoSize -Wrap | 
    Out-File -FilePath $FilePath -Width 120

notepad.exe $FilePath
