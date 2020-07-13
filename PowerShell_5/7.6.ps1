function Out-PDF
{
  param
  (
    $Path = "$env:TEMP\$(Get-Random).pdf",
    $Text = $null,
    $Title = $null,
    $Font = 'Courier',
    $FontSize = 12,
    $Width = 80,
    [Switch]$Open,
    [switch]$Landscape
  )

  if ($Text -eq $null)
  {
    $Text = $Input | Out-String -Width $Width
  }

  $WordObj = New-Object -ComObject Word.Application
  $document = $WordObj.Documents.Add()
  $document.PageSetup.Orientation = [Int][bool]$Landscape
  $document.Content.Text = $Text
  $document.Content.Font.Size = $FontSize
  $document.Content.Font.Name = $Font

  if ($Title -ne $null)
  {
    $WordObj.Selection.Font.Name = $Font
    $wordobj.Selection.Font.Size = 20
    $wordobj.Selection.TypeText($Title)
    $wordobj.Selection.ParagraphFormat.Alignment = 1
    $wordobj.Selection.TypeParagraph()
    $wordobj.Selection.TypeParagraph()
  }

  $saveaspath = [ref]$Path
  $formatPDF = [ref] 17
  $document.SaveAs($saveaspath,$formatPDF)
  $wdDoNotSaveChanges = 0
  $WordObj.NormalTemplate.Saved = $true
  $WordObj.Visible = $true
  $document.Close([ref]$wdDoNotSaveChanges)
  $WordObj.Quit([ref]$wdDoNotSaveChanges)

  if ($Open)
  {
    Invoke-Item -Path $Path
  }
}
