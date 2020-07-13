1..6 | Foreach-Parallel {
  $start = Get-Date -Format 'HH:mm:ss:ffffff'
  Write-Host "$start : Starte $_" -ForegroundColor Green
  Start-Sleep -Seconds 2
  $ende = Get-Date -Format 'HH:mm:ss:ffffff'
  Write-Host "$ende : Beende $_" -ForegroundColor Red

} -ThrottleLimit 2
