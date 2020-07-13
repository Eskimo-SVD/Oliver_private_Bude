Add-Type -AssemblyName System.Speech

$speaker = New-Object -TypeName System.Speech.Synthesis.SpeechSynthesizer -Property @{Rate = -10; Volume = 100}
$null = $Speaker.SpeakAsync('I am feeling dizzy!')
