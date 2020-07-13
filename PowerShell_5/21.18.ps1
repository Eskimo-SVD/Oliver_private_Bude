try
{
  1/0
}
catch [System.DivideByZeroException]
{
  Write-Warning 'Es wurde durch null geteilt!'
}
catch
{
  Write-Warning "Allgemeiner Fehler: $_"
}
