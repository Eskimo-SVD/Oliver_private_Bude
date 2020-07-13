workflow Test-Workflow
{
    InlineScript 
    {
      $hash = [Ordered]@{}
      $hash.'64bit Betriebsystem?' = [Environment]::Is64BitOperatingSystem
      $hash.'64bit Prozess?' = [Environment]::Is64BitProcess
      $hash.'Computername' = [Environment]::MachineName
      $hash.'Betriebsystem?' = [Environment]::OSVersion
      $hash.'Anzahl Kerne' = [Environment]::ProcessorCount

      New-Object PSObject -Property $hash
    }
}
