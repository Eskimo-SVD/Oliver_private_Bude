workflow Ping-Computer
{
  param
  (
    [String[]]
    $ComputerName
  )

  foreach -parallel -throttlelimit 40 ($Machine in $ComputerName)
  {
    Test-Connection -Count 1 -ComputerName $Machine -ErrorAction Ignore
  }
}

$Computer = Get-Content -Path 'c:\...\computerliste.txt'
Ping-Computer -ComputerName $Computer | Select-Object -Property Address, ResponseTime
