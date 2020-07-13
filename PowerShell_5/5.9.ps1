Get-ChildItem -Path $HOME -Filter *.ps1 -Recurse  |
  Get-AuthenticodeSignature |
  Where-Object { 'Valid', 'UnknownError' -notcontains $_.Status } |
  Select-Object -Property Path, Status, StatusMessage |
  Out-GridView
