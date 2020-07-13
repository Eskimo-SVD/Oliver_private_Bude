function Write-DelayMessage
{
    param($Info)
    "beginne Schritt $Info."
    Start-Sleep -Seconds 2
    "beende Schritt $Info."
}

workflow Test-Workflow
{
  parallel
    {
      Write-DelayMessage 1
      Write-DelayMessage 2
      Write-DelayMessage 3
    } 
}
