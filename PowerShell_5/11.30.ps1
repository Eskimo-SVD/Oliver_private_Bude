$xml = New-Object xml
$xml.Load('http://www.ecb.europa.eu/stats/eurofxref/eurofxref-daily.xml')

# aus den XML-Daten die Wechselkursinformationen ansprechen:
$xml.Envelope.Cube.Cube.Cube
