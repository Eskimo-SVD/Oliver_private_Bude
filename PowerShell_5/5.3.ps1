function prompt
{
  'PS> '
  $Host.UI.RawUI.WindowTitle = Get-Location
}

$Host.PrivateData.ErrorBackgroundColor = 'White'
$MaximumHistoryCount = 30KB
