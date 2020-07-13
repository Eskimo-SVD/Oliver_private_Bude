workflow Restart-Service
{
  sequence
  {
    InlineScript 
    {
        Stop-Service -Name MyApp -Force
        Stop-Service -name MyAppQueue -Force
    } -PSComputerName AppServer1
    

    parallel
    {
      InlineScript 
      {
        Remove-Item -Path "D:\MyApp\Files\MyAppQueue.xml" –Force
      } -PSComputerName ServerA

      InlineScript 
      {
        Remove-Item -Path "D:\MyApp\Files\MyAppQueue.xml" –Force
      } -PSComputerName ServerB
      

    } 

    InlineScript 
    {
        Start-Service -Name MyAppQueue -Force
        Start-Service -name MyApp -Force
    } -PSComputerName AppServer1
  }
}
