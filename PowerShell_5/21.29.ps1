do
{
  $ok = $false
  try
  {
    Get-Alter
    $ok = $true
  }
  catch
  {
    Write-Warning "Bitte geben Sie ein g�ltiges Datum ein!"
  }
} until ($ok)
