# Pfad in %PATH% aufnehmen ("Machine"-Set f�r alle User)
Invoke-DscResource -Name Environment -Method Set -ModuleName PSDesiredStateConfiguration -Property @{Name = 'Path'; Path = $true; Value = 'c:\newfolder';  Ensure = 'Present'}

# Erfolg �berpr�fen:
[Environment]::GetEnvironmentVariable('Path', 'machine') -split ';'
