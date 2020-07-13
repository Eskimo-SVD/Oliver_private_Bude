# requires full administrative permissions
# run in a PowerShell with elevated rights!

Update-Help -UICulture en-us -Force
$CurrentCulture = $Host.CurrentUICulture.Name
if ($CurrentCulture -ne 'en-us')
{
  if ( (Test-Path $PSHOME\$CurrentCulture) -eq $false)
  {
    $null = New-Item $PSHOME\$CurrentCulture -ItemType Directory
  }
  Copy-Item $PSHOME\en-us\* -Destination $PSHOME\$CurrentCulture -ErrorAction SilentlyContinue
}
