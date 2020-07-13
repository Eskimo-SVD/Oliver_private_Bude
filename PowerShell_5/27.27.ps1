# Pfad in %PATH% aufnehmen ("Machine"-Set für alle User)
Invoke-DscResource -Name Environment -Method Set -ModuleName PSDesiredStateConfiguration -Property @{Name = 'Test'; Path = $false; Value = '100';  Ensure = 'Present'}

# Erfolg überprüfen:
[Environment]::GetEnvironmentVariable('Test', 'machine')
