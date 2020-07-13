$text = 'Hallo Welt.'
$muster = 'Hallo (\w{1,})'
if ($text -match $muster) 
{ 
  $Matches[1] 
} 
else 
{ 
  Write-Warning 'nicht gefunden!' 
}
