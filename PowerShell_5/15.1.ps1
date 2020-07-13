function Get-PathComponent
{
  param
  (
    [Parameter(Mandatory=$true)]
    $Path
  )

  [System.IO.Path]::GetFileName($Path)
  [System.IO.Path]::GetFileNameWithoutExtension($Path)
  [System.IO.Path]::GetExtension($Path)
  [System.IO.Path]::GetDirectoryName($Path)
  [System.IO.Path]::GetPathRoot($Path)
  $Path
}
