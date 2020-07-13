$parameter = @{
  Dauer = 3000
  Frequenz = 500
}

Start-InNewThread -Code { param($Dauer, $Frequenz) [Console]::Beep($Frequenz, $Dauer) } -Parameters $parameter
