function Get-NestedDepth
{
  ForEach ($level in (1..100))
  {
    try
    {
      $variable = Get-Variable MyInvocation -Scope $level -ErrorAction SilentlyContinue
    }
    catch { return ($level-=2) }
  }
}
