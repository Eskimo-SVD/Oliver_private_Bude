#requires -Version 1


$zielordner = 'C:\Testbilder'
$index = 0

# alle Dateien im Testordner...
Get-ChildItem -Path $zielordner |
  # ...nach Gr��e aufsteigend sortieren...
  Sort-Object -Property Length |
  # ...danach mit laufender Nummer umbenennen:
  Rename-Item -NewName {
	  $datei = $_
	  $extension = $_.Extension
	  # Index um eins erh�hen
	  $script:index++
	  # neuen Dateinamen konstruieren 
	  'Picture{0:d3}{1}' -f $index, $extension
  }
  
  # Ordner �ffnen
  explorer $zielordner
