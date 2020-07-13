function Get-CriticalEvent
{
  param($Hours=48, [Switch]$ShowWindow)

  if ($ShowWindow)
  {
    # Die Ausgabe an das GridView umleiten
    Set-Alias -Name Out-Default -Value Out-GridView
  }

  $Heute = Get-Date
  $Differenz = New-TimeSpan -Hours $Hours
  $Stichtag = $Heute - $Differenz
  Get-EventLog -LogName System -EntryType Error, Warning -After $Stichtag |
    Select-Object -Property TimeGenerated, Message |
    Out-Default
}
