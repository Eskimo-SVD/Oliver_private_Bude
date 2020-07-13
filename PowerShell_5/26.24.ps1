# Logdateien löschen, falls vorhanden:
Remove-Item $env:temp\beforeSuspend.txt -ErrorAction Ignore
Remove-Item $env:temp\afterResume.txt -ErrorAction Ignore
 
workflow Test-RestartComputer
{
    Get-Date | Out-File -FilePath $env:temp\beforeSuspend.txt
 
    # Workflow unterbrechen
    Suspend-Workflow
 
    Get-Date | Out-File -FilePath $env:temp\afterResume.txt
}
