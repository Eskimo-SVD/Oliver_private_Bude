[System.Diagnostics.Process].Assembly.GetExportedTypes() |
  Where-Object { $_.isPublic} |
  Where-Object { $_.isClass } |
  Where-Object { $_.Name 
    -notmatch '(Attribute|Handler|Args|Exception|Collection|Expression|Parser|Statement)$' } |
  Select-Object -Property Name, FullName |
  Out-GridView
