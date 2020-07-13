$timer = New-Object Timers.Timer
$job = Register-ObjectEvent $timer -EventName Elapsed -Action { [System.Console]::Beep(1000,500) }
$timer.Interval = 2000
$timer.Enabled = $true
