#requires -Version 5
Enum ShowStates
{
  Hide                               = 0
  Normal                             = 1
  Minimized                          = 2
  Maximized                          = 3
  ShowNoActivateRecentPosition       = 4
  Show                               = 5
  MinimizeActivateNext               = 6
  MinimizeNoActivate                 = 7
  ShowNoActivate                     = 8
  Restore                            = 9
  ShowDefault                        = 10
  ForceMinimize                      = 11
}

function Set-Window
{
  [CmdletBinding(DefaultParameterSetName='WindowStyle')]
  param
  (
    [System.Diagnostics.Process]
    [Parameter(Mandatory=$true, ValueFromPipeline=$true)]
    $Process,
  
    [Parameter(ParameterSetName='WindowStyle', Mandatory=$true)]
    [ShowStates]
    $Window = [ShowStates]::Normal,

    [Parameter(ParameterSetName='TopMost', Mandatory=$true)]
    [Switch]
    $TopMost

  )
  
  begin
  {
    $code = @'
[DllImport("user32.dll")] public static extern bool ShowWindowAsync(IntPtr hWnd, int nCmdShow);
[DllImport("user32.dll")] public static extern bool SetWindowPos(IntPtr hWnd, IntPtr hWndInsertAfter, int X, int Y, int cx, int cy, uint uFlags);

'@
    $type = Add-Type -MemberDefinition $code -Name API -namespace Win32 -PassThru
  }
  
  process
  {
    if ($process.MainWindowHandle -eq 0)
    {
      Write-Warning "Process $process has no window."
    }
    else
    {
      if ($PSCmdlet.ParameterSetName -eq 'TopMost')
      {
        if ($TopMost.IsPresent)
        {
          $flag = New-Object -TypeName IntPtr(-1)
        }
        else
        {
          $flag = New-Object -TypeName IntPtr(-2)          
        }
        $type::SetWindowPos($process.MainWindowHandle, $flag, 0, 0, 0, 0, 3)
      }
      else
      {
        $type::ShowWindowAsync($process.MainWindowHandle, $Window)
      }
    }
  }
}


class AppInstance : System.Diagnostics.Process
{    
    
  # Konstruktor (wird beim Anlegen einer Instanz dieser Klasse aufgerufen)
  AppInstance([string]$Name, [System.Diagnostics.ProcessWindowStyle]$Window) : base()
  {
    $this.initialize($Name, $Window)
    $this.Hide()
  }
  
  AppInstance([string]$Name, [bool]$Hidden) : base()
  {
    if ($Hidden)
    {
      $this.initialize($Name, [System.Diagnostics.ProcessWindowStyle]::Minimized)
      $this.Hide()
    }
    else
    {
      $this.Initialize($Name, [System.Diagnostics.ProcessWindowStyle]::Normal)
    }
  }

  AppInstance([string]$Name) : base()
  {
    $this.Initialize($Name, [System.Diagnostics.ProcessWindowStyle]::Normal) 
  }
  
  hidden [void]Initialize([string]$Name, [System.Diagnostics.ProcessWindowStyle]$Window)
  {
    $this.StartInfo.FileName = $Name
    $this.Start()
    
    # warten, bis die Anwendung vollständig gestartet ist
    $this.WaitForInputIdle()
  }
  

  [void]Show() 
  {
    Set-Window -Process $this -Window ([ShowStates]::ShowDefault)
  }

  [void]Minimize() 
  {
    Set-Window -Process $this -Window ([ShowStates]::ForceMinimize)
  }
  
  [void]Maximize() 
  {
    Set-Window -Process $this -Window ([ShowStates]::Maximized)
  }
  
  [void]Hide() 
  {
    Set-Window -Process $this -Window ([ShowStates]::Hide)
  }

  [void]TopMost() 
  {
    Set-Window -Process $this -TopMost
  }

  [void]TopMost([bool]$ShowTopmost) 
  {
    Set-Window -Process $this -TopMost:$ShowTopmost
  }

  [void]Stop() 
  {
    $this.Kill()
  }
  
  [void]Close([Int]$Timeout = 0) 
  {
    # Aufforderung zum Schließen senden:
    $this.CloseMainWindow()
    
    # Auf Erfolg warten:
    if ($Timeout -gt 0)
    {
      $null = $this.WaitForExit($Timeout * 1000)
    }
    
    # falls Prozess immer noch läuft, sofort beenden
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
      Throw "Prozess mit PID $($this.Id) wird nicht mehr ausgeführt."
    }
  }
}
