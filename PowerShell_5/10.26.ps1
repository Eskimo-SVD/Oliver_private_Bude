function Get-Excuse
{
  $url = 'http://pages.cs.wisc.edu/~ballard/bofh/bofhserver.pl'
  $page = Invoke-WebRequest -Uri $url -UseBasicParsing
  $pattern = '(?s)<br><font size\s?=\s?"\+2">(.+)</font'

  if ($page.Content -match $pattern)
  {
    $matches[1]
  }
}
