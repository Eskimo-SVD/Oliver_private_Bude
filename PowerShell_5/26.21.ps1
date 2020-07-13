workflow Test-ParallelForeach
{
  param
  (
    [String[]]
    $ComputerName
  )

  foreach -parallel ($Machine in $ComputerName)
  {
    "Beginn $Machine"
    Start-Sleep -Seconds 4
    "Ende $Machine"
  }
}
