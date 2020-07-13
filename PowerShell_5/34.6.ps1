#requires -Version 5


class AppInstance 
{    
  # öffentliche Eigenschaften:
  [string]$Name 
  [System.Diagnostics.Process]$process

  # versteckte Eigenschaften:
  hidden [IntPtr]$hWnd 
    
  # Konstruktor (wird beim Anlegen einer Instanz dieser Klasse aufgerufen)
  AppInstance([string]$Name) 
  {
    $this.Name = $Name
    $this.process = Start-Process $this.Name -PassThru
    
    # warten, bis die Anwendung vollständig gestartet ist
    $this.process.WaitForInputIdle()
    $this.hWnd = $this.process.MainWindowHandle
  }

  [void]Stop() 
  {
    $this.process.Kill()
  }
  
  [void]Close([Int]$Timeout = 0) 
  {
    # Aufforderung zum Schließen senden:
    $this.process.CloseMainWindow()
    
    # Auf Erfolg warten:
    if ($Timeout -gt 0)
    {
      $null = $this.process.WaitForExit($Timeout * 1000)
    }
    
    # falls Prozess immer noch läuft, sofort beenden
    if ($this.process.HasExited -eq $false)
    {
      $this.Stop()
    }
  }
  
  [void]SetPriority([System.Diagnostics.ProcessPriorityClass] $Priority)
  {
    $this.process.PriorityClass = $Priority
  }
  
  [System.Diagnostics.ProcessPriorityClass]GetPriority()
  {
    if ($this.process.HasExited -eq $false)
    {
      return $this.process.PriorityClass 
    }
    else
    {
      Throw "Prozess mit PID $($this.process.Id) wird nicht mehr ausgeführt."
    }
  }

  static [System.Diagnostics.Process[]] GetAllProcesses()
  {
    return [AppInstance]::GetAllProcesses($false)
  }

  static [System.Diagnostics.Process[]] GetAllProcesses([bool]$All)
  {
    if ($All)
    {
      return Get-Process
    }
    else
    {
      return Get-Process | Where-Object { $_.MainWindowHandle -ne 0 }
    }
  }
}
