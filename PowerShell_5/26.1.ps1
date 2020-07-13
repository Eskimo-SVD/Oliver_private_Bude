function Restart-Service
{
  Invoke-Command -ComputerName AppServer1 {
    Stop-Service -Name MyApp -Force
    Stop-Service -Name MyAppQueue -Force
  }

  Invoke-Command -ComputerName ServerA, ServerB {
    Remove-Item -Path "D:\MyApp\Files\QueueLog.xml" –Force
  }

  Invoke-Command -ComputerName AppServer1 {
    Start-Service -Name MyAppQueue -Force
    Start-Service -Name MyApp -Force
  }
}
