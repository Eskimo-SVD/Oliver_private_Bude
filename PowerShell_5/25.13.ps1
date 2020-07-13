1..4 | Foreach-Parallel { 
  # an den Thread übergebene Zahl merken:
  $id = $_
  
  # Aufgabe mit Fortschrittsanzeige durchführen:
  1..100 |  ForEach-Object { 
    Write-Progress -id $id -Activity "Task $id" -Status 'Working...' -PercentComplete $_
    Start-Sleep -Milliseconds 30
  }
  Write-Progress -id $id -Activity "Task $id" -Status 'Completed!' -PercentComplete 100
} -ThrottleLimit 2
