function Out-ExcelReport
{
  param
  (
    $Path = "$env:TEMP\$(Get-Random).csv"
  )

  $Input | Export-Csv -Path $Path -Encoding UTF8 -NoTypeInformation -UseCulture
  Invoke-Item -Path $Path
}
