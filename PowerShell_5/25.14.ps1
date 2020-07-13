1..5 | Foreach-Parallel { 
  $s = Get-Random -Minimum 1 -Maximum 5
  Write-Host "Thread $_ wird $s sec. benötigen" -ForegroundColor Green
  
  Start-Sleep -Seconds $s
  
  return "Thread $_ wurde beendet" 
  } -TimeoutSec 3
