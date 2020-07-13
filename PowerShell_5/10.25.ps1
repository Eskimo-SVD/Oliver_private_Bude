$text = @'
Hier steht nichts.
Hier steht kb1234567.
Hier steht KB6635242.
'@

$pattern = '(?i)KB\d{6,8}'

[Regex]::Matches($text, $pattern)
