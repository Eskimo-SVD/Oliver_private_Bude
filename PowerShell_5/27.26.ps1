# Pfad in %PATH% aufnehmen ("Machine"-Set für alle User)
Invoke-DscResource -Name Environment -Method Set -ModuleName PSDesiredStateConfiguration -Property @{Name = 'Path'; Path = $true; Value = 'c:\newfolder';  Ensure = 'Absent'}

# Erfolg überprüfen:
[Environment]::GetEnvironmentVariable('Path', 'machine') -split ';'
