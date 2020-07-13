$template = @'

Ping wird ausgeführt für powershell.com [65.38.114.170] mit 32 Bytes Daten:
Antwort von {IP*:65.38.114.170}: Bytes=32 Zeit={Time:164}ms TTL={TTLValue:112}
Antwort von {IP*:100.38.4.70}: Bytes=32 Zeit={Time:1}ms TTL={TTLValue:1}
Antwort von {IP*:5.250.14.2}: Bytes=32 Zeit={Time:3000}ms TTL={TTLValue:99}
Zeitüberschreitung der Anforderung.

Ping-Statistik für 65.38.114.170:
    Pakete: Gesendet = 4, Empfangen = 3, Verloren = 1
    (25% Verlust),
Ca. Zeitangaben in Millisek.:
    Minimum = 163ms, Maximum = 165ms, Mittelwert = 164ms
'@

ping powershell.com | ConvertFrom-String -TemplateContent $template
ping powershellmagazine.com | ConvertFrom-String -TemplateContent $template
