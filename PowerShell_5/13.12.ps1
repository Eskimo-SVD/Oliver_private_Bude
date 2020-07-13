$Zähler = 
{
  begin { $i = 0 }
  process { $i++ }
  end { $i }
}


# wie viele Dienste gibt es?
$anzahl = Get-Service | & $Zähler
"Es gibt $anzahl Dienste."
