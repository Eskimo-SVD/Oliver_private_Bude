function Remove-LogFile
{
  param
  (
    $Path
  )
  
  $exists = Test-Path $path
  
  if ($exists)
  {
    Remove-Item -Path $path
  }
}
