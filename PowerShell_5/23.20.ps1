# Spooler-Dienst lokal abrufen
$dienst = Get-Service -Name Spooler
$dienst

# Spooler-Dienst �ber PowerShell Remoting abrufen
$dienst = Invoke-Command -ScriptBlock { Get-Service -Name Spooler } -Computername dell1
$dienst
