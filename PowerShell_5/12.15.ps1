function Speak-Text($text) {
  $speaker = New-Object -COMObject SAPI.SPVoice
  $speaker.Speak($text)
}
