function Get-CriticalEvent
{
  $Heute = Get-Date
  $Differenz = New-TimeSpan -Hours 48
  $Stichtag = $Heute - $Differenz
  Get-EventLog -LogName System -EntryType Error, Warning -After $Stichtag |
    Select-Object -Property TimeGenerated, Message
}
