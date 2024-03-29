#requires -Version 5


class AppInstance : System.Diagnostics.Process
{    
    
  # Konstruktor (wird beim Anlegen einer Instanz dieser Klasse aufgerufen)
  AppInstance([string]$Name) : base()
  {
    
    $this.StartInfo.FileName = $Name
    $this.Start()
    
    # warten, bis die Anwendung vollst�ndig gestartet ist
    $this.WaitForInputIdle()
  }

  [void]Stop() 
  {
    $this.Kill()
  }
  
  [void]Close([Int]$Timeout = 0) 
  {
    # Aufforderung zum Schlie�en senden:
    $this.CloseMainWindow()
    
    # Auf Erfolg warten:
    if ($Timeout -gt 0)
    {
      $null = $this.WaitForExit($Timeout * 1000)
    }
    
    # falls Prozess immer noch l�uft, sofort beenden
    if ($this.HasExited -eq $false)
    {
      $this.Stop()
    }
  }
  
  [void]SetPriority([System.Diagnostics.ProcessPriorityClass] $Priority)
  {
    $this.PriorityClass = $Priority
  }
  
  [System.Diagnostics.ProcessPriorityClass]GetPriority()
  {
    if ($this.HasExited -eq $false)
    {
      return $this.PriorityClass 
    }
    else
    {
      Throw "Prozess mit PID $($this.Id) wird nicht mehr ausgef�hrt."
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
