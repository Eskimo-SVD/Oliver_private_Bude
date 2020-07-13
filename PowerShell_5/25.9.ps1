function Start-Progress
{
  param
  (
    [scriptblock]
    $code
  )

  $newPowerShell = [powershell]::Create().AddScript($code)
  $handle = $newPowerShell.BeginInvoke()

  while ($handle.IsCompleted -eq $false) {
    Write-Host '.' -NoNewline
    Start-Sleep -Milliseconds 500
  }
  Write-Host ''

  $newPowerShell.EndInvoke($handle)

  # zweiten Thread ordnungsgem‰ﬂ entsorgen:
  $newPowerShell.Runspace.Close()
  $newPowerShell.Dispose()
}
