function Convert-PNG2Base64 
{
  param
  (
    [Parameter(Mandatory=$true)]
    $Path
  )

  $format = [System.Drawing.Imaging.ImageFormat]::Png

  $image = [System.Drawing.Image]::FromFile($Path)
  $stream = New-Object -TypeName System.IO.MemoryStream
  $image.Save($stream, $format)
  $bytes = [Byte[]]($stream.ToArray())
  [System.Convert]::ToBase64String($bytes, 'InsertLineBreaks')
}
 
Convert-PNG2Base64 -Path 'C:\...\bild.png' | clip.exe
