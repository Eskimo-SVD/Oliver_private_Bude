function Ping-Computer
{
  param
  (
    [Parameter(Mandatory=$true)]
    [String[]]
    $ComputerName,
  
    $Timeout = 4000
  )

  $Filter = ($ComputerName | 
     ForEach-Object { 'Address="{0}" and Timeout={1}' -f $_, $Timeout}) -join ' or '
  
  Get-WmiObject -Class Win32_PingStatus -Filter $filter |
  Select-Object -Property Address, ProtocolAddress, ResponseTime, Timeout 
  
}


$liste = 'powertheshell.com', 'powershellmagazine.com', 'powershell.com'
Ping-Computer -ComputerName $liste
