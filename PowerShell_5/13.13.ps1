function Get-ObjectCount 
{
  begin { $i = 0 }
  process { $i++ }
  end { $i }
}


# wie viele Dienste gibt es?
$anzahl = Get-Service | Get-ObjectCount
"Es gibt $anzahl Dienste."
