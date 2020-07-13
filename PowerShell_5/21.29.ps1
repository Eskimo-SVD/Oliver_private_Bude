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
    Write-Warning "Bitte geben Sie ein gültiges Datum ein!"
  }
} until ($ok)
