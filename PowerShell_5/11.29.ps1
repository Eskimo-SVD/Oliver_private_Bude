# Wetterdienst ansprechen:
$wetter = New-WebServiceProxy -Uri http://www.webservicex.com/globalweather.asmx?WSDL

# Wetterdaten abrufen:
$hannover = [xml]$wetter.GetWeather('Hannover', 'Germany')
$mallorca = [xml]$wetter.GetWeather('Palma', 'Spain')
$celsiusHannover =
if ($hannover.CurrentWeather.Temperature -match 'F \((.*?) C\)')
{
  $Matches[1]
}

$celsiusPalma =
if ($mallorca.CurrentWeather.Temperature -match 'F \((.*?) C\)')
{
  $Matches[1]
}

$differenz = $celsiusPalma - $celsiusHannover

"In Palma de Mallorca ist es gerade $differenz Grad Celsius wärmer."

# HTML-Report der Wetterdaten anlegen und öffnen:
$mallorca.currentweather, $hannover.currentweather |
  Select-Object Location, Time, Wind, Visibility, Temperature, DewPoint, RelativeHumidity, Pressure, Status |
  ConvertTo-Html -Title 'Wetterbericht Palma und Hannover' |
  Out-File $env:TEMP\wetter.hta

# Report öffnen:
Invoke-Item $env:TEMP\wetter.hta
