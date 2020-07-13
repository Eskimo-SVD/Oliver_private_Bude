$speaker = New-Object -ComObject SAPI.SpVoice
$null = $speaker.Speak('Hello World!')
$speaker.Rate = -10
$null = $speaker.Speak('Hello World!')
