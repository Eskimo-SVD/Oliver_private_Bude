$path = "$env:temp\report.csv"

Get-EventLog -LogName System -Newest 10 |
  Select-Object -Property TimeWritten, Message, EntryType, ReplacementStrings |
  ForEach-Object {
    $_.ReplacementStrings = $_.ReplacementStrings -join ', '
    $_
  } |
  Export-CSV -Path $path -UseCulture -NoTypeInformation -Encoding UTF8
  
Invoke-Item -Path $path
