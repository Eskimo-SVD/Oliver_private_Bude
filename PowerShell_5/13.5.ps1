$Code = 
{
  # Die letzten 5 Fehler-Eintr�ge aus dem System-Logbuch lesen
  Get-EventLog -LogName System -EntryType Error -Newest 5
}

Invoke-Command -ScriptBlock $Code -ComputerName Server_012_win
