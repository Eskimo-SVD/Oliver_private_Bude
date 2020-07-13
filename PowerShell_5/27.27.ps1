# Pfad in %PATH% aufnehmen ("Machine"-Set f�r alle User)
Invoke-DscResource -Name Environment -Method Set -ModuleName PSDesiredStateConfiguration -Property @{Name = 'Test'; Path = $false; Value = '100';  Ensure = 'Present'}

# Erfolg �berpr�fen:
[Environment]::GetEnvironmentVariable('Test', 'machine')
