function Test-IPv4 
{
  param($IPAddress)
  
  $IP = $IPAddress -as [System.Net.IPAddress]
  $IP.AddressFamily -eq 'InternetWork' -and $IPAddress -like '*.*.*.*'  
}
