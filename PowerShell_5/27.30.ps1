Find-Module -Tag DSC | 
  Select -Property Name, Author, Version, PublishedDate, Description, ProjectUri | 
  Sort-Object -Property PublishedDate -Descending |
  Out-GridView
