filter grep($stichwort) 
{
  # ist das Objekt ein Text?
  $noText = $_ -isnot [string]
  # falls nicht, muss das Objekt in Text umgewandelt werden
  if ($noText)
  {
    $text = $_ | 
    # ...sicherstellen, dass dabei keine Informationen abgeschnitten
    # werden, indem bis zu 5000 Zeichen lange Zeilen erlaubt werden:
    Format-Table -AutoSize | 
    Out-String -Width 5000 -Stream | 
    # die ersten drei Textzeilen verwerfen, die die Spaltenüberschriften
    # enthalten:
    Select-Object -Skip 3
  }
  else
  {
    # einlaufende Information war bereits Text:
    $text = $_
  }
  
  # Objekt herausfiltern, wenn das Stichwort nicht in seiner
  # Textrepräsentation gefunden wird
  # Dabei das Platzhalterzeichen "*" am Anfang und Ende des Stichworts
  # bereits vorgeben (sucht das Stichwort "irgendwo" im Text):
  $_ | Where-Object { $text -like "*$stichwort*" }
}
