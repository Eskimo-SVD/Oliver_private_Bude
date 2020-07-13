$scriptBlock = { [IntPtr]::Size }

$32bitPowerShell = "$env:windir\SysWOW64\WindowsPowerShell\v1.0\powershell.exe"

& $scriptBlock
& $32bitPowerShell $scriptBlock
