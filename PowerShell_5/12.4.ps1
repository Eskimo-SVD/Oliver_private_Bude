function Get-CriticalEvent
{
  param
  (
    # Das Zeitfenster in Stunden, das berücksichtigt werden soll
    [Int]
    $Hours=48, # <- wichtig, Komma nicht vergessen!
    
    # zeigt die Ergebnisse in einem Fenster an
    [Switch]
    $ShowWindow
  )

  $Heute = Get-Date
  $Differenz = New-TimeSpan -Hours 48
  $Stichtag = $Heute - $Differenz
  Get-EventLog -LogName System -EntryType Error, Warning -After $Stichtag |
    Select-Object -Property TimeGenerated, Message
}
