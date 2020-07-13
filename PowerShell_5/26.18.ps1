workflow Test-Workflow
{
  parallel
    {
      Get-HotFix
      Get-Service
      Get-Process
    } 
}

$ergebnis = Test-Workflow
$ergebnis.Count
