if([System.Windows.Input.Keyboard]::IsKeyDown('Ctrl') -eq $true) 
{ 
  Set-StrictMode -Version Latest
  $DebugPreference = 'Continue'
  $VerbosePreference = 'Continue'
  Write-Debug 'Debug-Mode aktiviert.'
}
