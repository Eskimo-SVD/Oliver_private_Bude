$code = 
{
  '{0:n1} MB' -f ($this/1MB)
}
$zahl = 576235342 | Add-Member -MemberType ScriptMethod -Name toString -Value $code -Force -PassThru
