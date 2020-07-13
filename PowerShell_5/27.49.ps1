function Start-DscMonitor
{
  $code = {
    param($hostobj)
    do
    {
        $status = (Get-DscLocalConfigurationManager).LCMStateDetail
        if (!$status) { $status = 'LCM is idle' }
        $hostobj.ui.RawUI.WindowTitle = $status
        Start-Sleep -Milliseconds 300
    } while ($true)
  }

  $global:OldTitle = $host.UI.RawUI.WindowTitle
  $global:DSCMonitor = [PowerShell]::Create()
  $null = $global:DSCMonitor.AddScript($code).AddArgument($host)
  $null = $global:DSCMonitor.BeginInvoke()
  Write-Warning 'DSC Monitor enabled. Use Stop-DscMonitor to disable'
}

function Stop-DscMonitor
{
  if ($global:DSCMonitor -eq $null) { return }
  
  $global:DSCMonitor.Runspace.Close()
  $global:DSCMonitor.Dispose()
  $global:DSCMonitor = $null
  $host.UI.RawUI.WindowTitle = $global:OldTitle
}
