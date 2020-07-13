$Code = {
  "A = $a"
  $a = 12
  "A = $a"
}

$a = 1000
& $Code
"Am Ende ist A = $a"
