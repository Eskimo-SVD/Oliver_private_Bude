try
{
  # diesen Fehler analysieren:
  1/0
}
catch
{
  if ($_.Exception.InnerException)
  {
    Write-Warning $_.Exception.InnerException.GetType().FullName 
  }
  else
  {
    Write-Warning $_.Exception.GetType().FullName 
  }
}
