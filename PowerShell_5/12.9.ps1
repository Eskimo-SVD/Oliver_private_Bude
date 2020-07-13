function Get-CriticalEvent
{
<#
    .SYNOPSIS
        listet Fehler und Warnungen aus dem System-Ereignisprotokoll auf
    .DESCRIPTION
        liefert Fehler und Warnungen der letzten 48 Stunden aus dem System-Ereignisprotokoll, die auf Wunsch in einem GridView angezeigt werden. Der Beobachtungszeitraum kann mit dem Parameter -Hours geändert werden.
    .EXAMPLE
        Get-CriticalEvent
        liefert Fehler und Warnungen der letzten 48 Stunden aus dem System-Ereignisprotokoll
    .EXAMPLE
        Get-CriticalEvent -Hours 100
        liefert Fehler und Warnungen der letzten 100 Stunden aus dem System-Ereignisprotokoll
    .EXAMPLE
        Get-CriticalEvent -Hours 24 -ShowWindow
        liefert Fehler und Warnungen der letzten 24 Stunden aus dem System-Ereignisprotokoll und stellt sie in einem eigenen Fenster dar
    .NOTES
        Dies ist ein Beispiel aus Tobias Weltners' PowerShell Buch
    .LINK
        http://www.powertheshell.com
#>
  param
  (
    # Anzahl der Stunden des Beobachtungszeitraums. Vorgabe ist 48.
    $Hours=48, 
    
    # Wenn dieser Switch-Parameter angegeben wird, erscheint das Ergebnis in einem eigenen Fenster und wird nicht in die Konsole ausgegeben
    [Switch]$ShowWindow
  )

  if ($ShowWindow)
  {
    Set-Alias Out-Default Out-GridView
  }

  $Heute = Get-Date
  $Differenz = New-TimeSpan -Hours $Hours
  $Stichtag = $Heute - $Differenz

  Get-EventLog -LogName System -EntryType Error, Warning -After $Stichtag |
    Select-Object -Property TimeGenerated, Message | Out-Default
}
