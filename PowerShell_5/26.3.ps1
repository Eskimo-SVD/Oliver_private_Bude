function Write-DelayMessage
{
    param($Info)
    "beginne Schritt $Info."
    Start-Sleep -Seconds 2
    "beende Schritt $Info."
}

workflow Test-Workflow
{
  sequence
  {
    Write-DelayMessage 1
    

    parallel
    {
      Write-DelayMessage 2
      Write-DelayMessage 3
      Write-DelayMessage 4
    } 

    Write-DelayMessage 5
  }
}
