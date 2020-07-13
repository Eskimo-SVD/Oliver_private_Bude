function Start-InNewThread
{
  param
  (
    [ScriptBlock]$Code,
    
    [Hashtable]$Parameters = @{}
  )
  
  $powershell = [PowerShell]::Create()
  $action = {
   
    $status = $event.SourceEventArgs.InvocationStateInfo.State
    
    if ($status -eq 'Completed')
    {
      try
      {
        $powershell = $event.Sender
        $powershell.Runspace.Close()
        $powershell.Dispose()
        Unregister-Event -SourceIdentifier $event.SourceIdentifier 
      }
      catch
      {
        Write-Warning "$_"
      }
    }
  }
  
  $null = Register-ObjectEvent -InputObject $powershell -Action $action -EventName InvocationStateChanged 
  $null = $powershell.AddScript($Code)
  
  foreach($key in $Parameters.Keys)
  {
    $null = $powershell.AddParameter($key, $Parameters.$key)
  }
 
  $handle = $powershell.BeginInvoke()
}
