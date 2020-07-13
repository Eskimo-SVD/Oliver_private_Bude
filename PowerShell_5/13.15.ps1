$aquarium = Get-Service

foreach ($fisch in $aquarium)
{
  $dienstname = $fisch.DisplayName
  "Ich angle gerade $dienstname"
}
