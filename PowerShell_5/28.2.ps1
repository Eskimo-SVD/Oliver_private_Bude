$job = Invoke-Command -Computer storage1 { dir $env:windir *.log -Recurse -ea 0 } -AsJob
Register-ObjectEvent $job -EventName StateChanged -SourceIdentifier JobEnd -Action {
  if($job.State -eq "Completed")
    {
      Write-Host 'Hintergrundjob ist fertig!' -Back 'White' -Fore 'Red'
      Write-Host "$(Receive-Job $job | Out-String)"
      Unregister-Event -SourceIdentifier JobEnd
      Remove-Job -Name JobEnd
      Remove-Job $job
    }
  } | Out-Null
