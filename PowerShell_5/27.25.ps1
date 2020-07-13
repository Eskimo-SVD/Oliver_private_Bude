# Pfad in %PATH% aufnehmen ("Machine"-Set für alle User)
Invoke-DscResource -Name Environment -Method Set -ModuleName PSDesiredStateConfiguration -Property @{Name = 'Path'; Path = $true; Value = 'c:\newfolder';  Ensure = 'Present'}

# Erfolg überprüfen:
[Environment]::GetEnvironmentVariable('Path', 'machine') -split ';'
