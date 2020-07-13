function Get-PathComponent
{
  param
  (
    [Parameter(Mandatory=$true)]
    $Path
  )

  $erg = 1 | Select-Object -Property Parent, FileName, Extension, Drive, BaseName, Path
  $erg.FileName = [System.IO.Path]::GetFileName($Path)
  $erg.BaseName = [System.IO.Path]::GetFileNameWithoutExtension($Path)
  $erg.Extension = [System.IO.Path]::GetExtension($Path)
  $erg.Parent = [System.IO.Path]::GetDirectoryName($Path)
  $erg.Drive  = [System.IO.Path]::GetPathRoot($Path)
  $erg.Path = $Path
  $erg 
}
