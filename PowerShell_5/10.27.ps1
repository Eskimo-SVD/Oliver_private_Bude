function Get-Excuse
{
  $url = 'http://pages.cs.wisc.edu/~ballard/bofh/bofhserver.pl'
  $page = Invoke-WebRequest -Uri $url -UseBasicParsing
  $pattern = '(?<=<br><font size\s?=\s?"\+2">).+'
  if ($page.Content -match $pattern)
  {
    $matches[0]
  }
}