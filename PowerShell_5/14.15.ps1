# diese Webseite untersuchen:
$URL = 'www.tagesschau.de'
$destination = 'c:\webpics'
$existiert = Test-Path -Path $destination
if ($existiert -eq $false) { mkdir $destination }

try
{
  # Inhalt der Webseite abrufen und in $result speichern
  # -UseBasicParsing verhindert Dialogfelder
  $result = Invoke-WebRequest -Uri $URL -UseBasicParsing -ErrorAction Stop

  # alle Images aus der Webseite abrufen
  $result.Images | 
  # und daraus die Eigenschaft "src" auflisten:  
  Select-Object -ExpandProperty src |
  # jede URL nur einmal herunterladen
  Sort-Object -Unique |
  # Links, die Parameter enthalten, wollen wir nicht:
  Where-Object { $_ -notmatch '\?'} |
  # jede einzelne URL nun bearbeiten:
  ForEach-Object { 
    # die empfangene einzelne URL einer eigenen Variable zuweisen:
    $linkUrl = $_

    # wenn die URL nicht mit "http" beginnt...
    if ($linkUrl -notlike 'http*')
    {
      # ...dann eine absolute URL daraus machen, indem die 
      # Adresse der Webseite vorangestellt wird
      $linkUrl = "http://$URL/$linkUrl"
    }

    # Ergebnis wieder zurückgeben:
    $linkUrl
  } | ForEach-Object {
    # wir empfangen eine absolute URL des Bildes:
    $absoluteLinkURL = $_

    # hier sollen die Bilder gespeichert werden:
    $filename = Split-Path -Path $absoluteLinkURL -Leaf
    $destinationPath = Join-Path -Path $destination -ChildPath $filename

    # Bild herunterladen
    $NewPath = $destinationPath
    $Counter = 0
  
    # so lange an den Dateinamen eine Zahl anhängen, bis
    # die Datei nicht mehr existiert:
    While (Test-Path -Path $NewPath)
    {
      # neuen Dateinamen erzeugen
      $Counter++
      $parts = $destinationPath.Split('.')
      $parts[-2]+= "($Counter)"
      $NewPath = $parts -join '.'
    }
  
    Invoke-WebRequest -Uri $absoluteLinkURL -OutFile $NewPath  
  
  }
}
catch {} 

# Bilderordner öffnen
explorer $destination
