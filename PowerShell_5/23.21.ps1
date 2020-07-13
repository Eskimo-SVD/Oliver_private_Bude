# Spooler-Dienst lokal abrufen
$dienst = Get-Service -Name Spooler
$dienst.GetType().FullName
$dienst.PSTypeNames[0]

# Spooler-Dienst über PowerShell Remoting abrufen
$dienst = Invoke-Command -ScriptBlock { Get-Service -Name Spooler } -Computername dell1
$dienst.GetType().FullName
$dienst.PSTypeNames[0]
