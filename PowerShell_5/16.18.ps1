function Enable-AutoPageFile {
  [CmdletBinding(SupportsShouldProcess=$True)]
  param()

  $computer = Get-WmiObject -class Win32_ComputerSystem -EnableAllPrivileges
  $computer.AutomaticManagedPagefile=$true
  if ($PSCmdlet.ShouldProcess($env:COMPUTERNAME, "Automatische Auslagerungsdatei einschalten"))
  {
    $computer.Put() | Out-Null
  }
}
