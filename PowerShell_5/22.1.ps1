function Test-NetworkPort
{
  param
  (
    $ComputerName = $env:COMPUTERNAME,

    [int32[]]
    [Parameter(ValueFromPipeline=$true)]
    $Port = $(137..139 + 445 + 5985),

    [int32]
    $Timeout=1000,

    [switch]
    $AllResults
  )

  process
  {
    $count = 0
    ForEach ($PortNumber in $Port)
    {
      $count ++
      $perc = $count * 100 / $Port.Count
      Write-Progress -Activity "Scanning on \\$ComputerName" -Status "Port $PortNumber" -PercentComplete $perc

      # in PowerShell 2.0 muss [Ordered] entfernt werden
      # dann ist die Reihenfolge der Eigenschaften aber zufällig.
      $result = New-Object PSObject -Property ([Ordered]@{
        Port="$PortNumber"; Open=$False; Type='TCP'; ComputerName=$ComputerName})

      $TCPClient = New-Object System.Net.Sockets.TcpClient
      $Connection = $TCPClient.BeginConnect($ComputerName, $PortNumber, $null, $null)

      try
      {
        if ($Connection.AsyncWaitHandle.WaitOne($Timeout, $false))
        {
          $null = $TCPClient.EndConnect($Connection)
          $result.Open = $true
        }
      }
      catch {} finally { $TCPClient.Close() }

      $result | Where-Object { $AllResults -or $_.Open }
    }
  }
}
