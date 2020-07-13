$wert = 0
$Code = { "Wert = $wert" }.GetNewClosure()

$wert = 1
& $Code 

$wert = 2
& $Code
