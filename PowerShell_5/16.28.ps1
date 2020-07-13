Add-Type -AssemblyName System.Speech

$speaker = [System.Speech.Synthesis.SpeechSynthesizer] @{Rate = -10; Volume = 100}
$null = $Speaker.SpeakAsync('I am feeling dizzy!')
