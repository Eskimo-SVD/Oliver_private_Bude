function New-File 
{
  param
  (
    [Parameter(Mandatory = $true)]
    $Path
  )
  
  $exists = Test-Path -Path "FileSystem::$Path"
  
  if (!$exists)
  {
    New-Item -Path $Path -ItemType File -Force
  }
  else
  {
    Get-Item -Path $Path
  }
}
