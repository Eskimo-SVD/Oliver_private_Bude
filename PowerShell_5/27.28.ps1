Invoke-DscResource -Name Group -Method Set -ModuleName PSDesiredStateConfiguration -Property @{GroupName = 'PowerShellUsers'; Description = 'created by DSC'; Ensure = 'Present'}

# überprüfen
net localgroup
