Add-Type -AssemblyName System.Speech
$speaker = New-NETObject System.Speech.Synthesis.SpeechSynthesizer -Rate 1 -Volume 100
$speaker.Speak('Hello World!')
