workflow Test-Workflow
{
  parallel
  {
    $workflow:hotfix = Get-HotFix
    $workflow:service = Get-Service
    $workflow:process = Get-Process
  }
    
  $hotfix, $service, $process
}

$ergebnis = Test-Workflow
$ergebnis.Count
