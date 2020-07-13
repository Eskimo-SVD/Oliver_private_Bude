$text = 'Hallo Welt.'
$positionAnfang = $text.IndexOf('Hallo') + 6
$positionEnde = $text.IndexOf('.', $positionAnfang+1)
$text.Substring($positionAnfang, $positionEnde - $positionAnfang)
