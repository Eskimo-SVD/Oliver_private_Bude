function Get-ImageFromWebsite
{
  param
  (
    [Parameter(Mandatory = $true)]
    [String]
    $URL ,
    
    [String]
    $Filter = ''
  )


  # Inhalt der Webseite abrufen und in $result speichern
  # -UseBasicParsing verhindert Dialogfelder
  $result = Invoke-WebRequest -Uri $URL -UseBasicParsing

  # alle Images aus der Webseite abrufen
  $result.Images | 
  # und daraus die Eigenschaft "src" auflisten:  
  Select-Object -ExpandProperty src |
  # jede URL nur einmal herunterladen
  Sort-Object -Unique |
  # Links, die Parameter enthalten, wollen wir nicht:
  Where-Object { $_ -notmatch '\?'} |
  ConvertTo-AbsoluteURL -WebsiteURL $URL |
  Where-Object { $_ -like "*$Filter" }
}
