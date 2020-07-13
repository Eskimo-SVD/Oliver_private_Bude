$code = {
    Start-Sleep -Seconds 2
    "Hello"
}

$newPowerShell = [powershell]::Create().AddScript($code)
$newPowerShell.Invoke()
