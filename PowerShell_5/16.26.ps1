Add-Type -AssemblyName System.Speech
$Speaker = New-Object System.Speech.Synthesis.SpeechSynthesizer XE "System.Speech.Synthesis.SpeechSynthesizer" 
$Speaker.Rate = -10
$Speaker.Volume = 100
$null = $Speaker.SpeakAsync('I am feeling dizzy!')
