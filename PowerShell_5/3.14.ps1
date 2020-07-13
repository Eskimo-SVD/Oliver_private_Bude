#requires -Version 1


$zielordner = 'C:\Testbilder'
$index = 0

# alle Dateien im Testordner...
Get-ChildItem -Path $zielordner |
  # ...nach Größe aufsteigend sortieren...
  Sort-Object -Property Length |
  # ...danach mit laufender Nummer umbenennen:
  Rename-Item -NewName {
	  $datei = $_
	  $extension = $_.Extension
	  # Index um eins erhöhen
	  $script:index++
	  # neuen Dateinamen konstruieren 
	  'Picture{0:d3}{1}' -f $index, $extension
  }
  
  # Ordner öffnen
  explorer $zielordner
