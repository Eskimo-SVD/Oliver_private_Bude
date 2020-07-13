function Do-Every
{
   param([int] $seconds,[scriptblock] $action )
   $timer = New-Object System.Timers.Timer
   $timer.Interval = $seconds * 1000
   $timer.Enabled = $true
   Register-ObjectEvent $timer "Elapsed" -SourceIdentifier 'DoEvery' -Action $action
}

function Clean-Every
{
  Unregister-Event DoEvery
  Remove-Job -name DoEvery
}
