function Get-HelloWorld 
{
  param
  (
    $Name = ''
  )

  if ($Name.Length -gt 0) 
  {
    $Name = ' ' + $Name
  }

  "Hello World$Name!"
}
