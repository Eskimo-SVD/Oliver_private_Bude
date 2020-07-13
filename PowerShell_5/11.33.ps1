function Find-TypeByName
{
  param
  (
    [Parameter(Mandatory=$true)]
    $Keyword
  )

  [AppDomain]::CurrentDomain.GetAssemblies() |
    ForEach-Object { try { $_.GetExportedTypes() } catch {} } |
    Where-Object { $_.isPublic} |
    Where-Object { $_.isClass } |
    Where-Object { $_.Name -notmatch '(Attribute|Handler|Args|Exception|Collection|Expression)$' }|
    Where-Object { $_.Name -like "*$Keyword*" } |
    Select-Object -Property Name, FullName
}
