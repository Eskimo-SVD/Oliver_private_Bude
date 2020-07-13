workflow Test-Workflow
{
  parallel
  {
    $workflow:hotfix = InlineScript  { Get-HotFix }
    $workflow:service = InlineScript { Get-Service }
    $workflow:process = InlineScript { Get-Process }
  }
    
  $hotfix, $service, $process
}

$ergebnis = Test-Workflow
$ergebnis.Count
