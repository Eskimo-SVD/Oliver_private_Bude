PS> $os = Get-WmiObject -Class Win32_OperatingSystem
PS> $InstallDate = $os.InstallDate
PS> $LastBootDate = $os.LastBootUpTime

PS> $InstallDate
20120806185927.000000+120

PS> $LastBootDate
20121113065721.356498+060
