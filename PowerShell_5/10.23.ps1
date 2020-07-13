$quellcode = '<a href="eine adresse">Link 1</a><a href="noch eine">Link 2</a>'
$pattern = '(?i)<a href="(?<link>.*?)".*?>(?<text>.*?)</a>'
[RegEx]::Matches($quellcode, $pattern)
