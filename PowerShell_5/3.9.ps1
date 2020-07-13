#requires -Version 1
$desktop = "$home\Desktop"
Get-ChildItem -Path $desktop -Filter *.ps1 |
  Copy-Item -Destination { 
	  $datei = $_
	  $name = $datei.Name
	  $newname = $name + '.bak'
	  Join-Path -Path $desktop -ChildPath $newname
	}
