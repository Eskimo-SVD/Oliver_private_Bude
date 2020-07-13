function Get-CriticalEvent
{
  param([Int]$Hours=48, [Switch]$ShowWindow)

  $Heute = Get-Date
  $Differenz = New-TimeSpan -Hours 48
  $Stichtag = $Heute - $Differenz
  Get-EventLog -LogName System -EntryType Error, Warning -After $Stichtag |
    Select-Object -Property TimeGenerated, Message
}
