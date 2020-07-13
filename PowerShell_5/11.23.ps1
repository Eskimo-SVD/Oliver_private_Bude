$speaker = New-Object -ComObject SAPI.SpVoice -Property @{Speak='Initializing'}
$speaker.Rate = -20
$null = $speaker.Speak('What a night!')
