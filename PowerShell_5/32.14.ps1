function Restart-InactiveComputer
{
  $explorer = Get-Process -Name explorer -ErrorAction SilentlyContinue
  if ($explorer.Count -eq 0)
  {
    Restart-Computer -Force
  }
}