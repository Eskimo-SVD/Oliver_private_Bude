function Test-ParameterDynamicInvoke
{
  [CmdletBinding()]
  param()

  dynamicparam
  {
    [Console]::Beep(440, 300)
  }
  
}
