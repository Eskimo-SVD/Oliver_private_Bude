$Z�hler = 
{
  begin { $i = 0 }
  process { $i++ }
  end { $i }
}


# wie viele Dienste gibt es?
$anzahl = Get-Service | & $Z�hler
"Es gibt $anzahl Dienste."
