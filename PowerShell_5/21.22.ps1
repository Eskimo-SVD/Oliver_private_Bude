function Invoke-ScriptBlock
{

  param
  (
    [ScriptBlock]
    [Parameter(Mandatory = $true)]
    $ScriptBlock
  )
  
  $ErrorActionPreference = 'Stop'
  try
  {
    $ScriptBlock.Invoke()
  }

  catch [System.Management.Automation.ItemNotFoundException]
  {
    Write-Warning "Ein Element wurde nicht gefunden: $_"
  }

  catch [System.DivideByZeroException]
  {
    Write-Warning 'Sie haben durch null dividiert'
  }

  catch [Microsoft.PowerShell.Commands.ProcessCommandException]
  {
    Write-Warning 'Sie haben Get-Process einen Prozessnamen genannt, aber solch ein Programm läuft nicht.'
  }

  catch [System.Management.Automation.RemoteException]
  {
    Write-Warning "Es ist ein Problem beim Aufruf eines Konsolenbefehls aufgetreten: $_"
  }

  catch
  {
    Write-Warning "Es ist ein allgemeiner Fehler aufgetreten: $_"
  }
}

Invoke-ScriptBlock { Get-ChildItem -Path c:\gibtesnicht }
Invoke-ScriptBlock { Get-Process -Name gibtsnicht }
Invoke-ScriptBlock { net.exe user gibtsnicht }
