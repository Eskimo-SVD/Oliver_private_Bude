$text = 'Meine E-Mail lautet tobias.weltner@irgendwo.de. Alternativ können Sie auch an tobias@somewhere.com oder tobias.weltner@powertheshell.com mailen.'

$regex = [regex]'(?i)\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]{2,4}\b'

$regex.Matches($text).Value
