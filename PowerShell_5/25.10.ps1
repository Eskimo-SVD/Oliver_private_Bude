function Start-Timebomb
{
  param
  (
    [int32]
    [Parameter(Mandatory=$true)]
    [ValidateRange(5,600)]
    $Seconds,

    [scriptblock]
    $Action = { Stop-Process -Id $PID }
  )

  $Wait = "Start-Sleep -seconds $seconds"
  $script:newPowerShell = [powershell]::Create().AddScript($Wait).AddScript($Action)
  $handle = $newPowerShell.BeginInvoke()
  Write-Warning "Timebomb is active and will go off in $Seconds seconds unless you call Stop-Timebomb before."
}

function Stop-Timebomb
{
  if ($script:newPowerShell -ne $null)
  {
    Write-Host 'Trying to stop timebomb...' -NoNewline
    $script:newPowerShell.Stop()
    $script:newPowerShell.Runspace.Close()
    $script:newPowerShell.Dispose()
    Remove-Variable newPowerShell -Scope script
    Write-Host 'Done!'
  }
  else
  {
    Write-Warning 'No timebomb found.'
  }
}
