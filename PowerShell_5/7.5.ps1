function Out-WinWord
{
  param
  (
    $Text = $null,
    $Title = $null,
    $Font = 'Courier',
    $FontSize = 12,
    $Width = 80,
    [Switch]$Print,
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

  if ($Print)
  {
    $WordObj.PrintOut()
    $wdDoNotSaveChanges = 0
    $WordObj.NormalTemplate.Saved = $true
    $WordObj.Visible = $true
    $document.Close([ref]$wdDoNotSaveChanges)
    $WordObj.Quit([ref]$wdDoNotSaveChanges)
  }
  else
  {
    $WordObj.Visible = $true
  }
}
