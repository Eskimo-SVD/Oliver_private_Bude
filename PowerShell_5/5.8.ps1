# $cert muss bereits ein g�ltiges digitales Zertifikat enthalten (siehe Buch)
# entfernen Sie -whatIf, um die Signaturen tats�chlich einzuf�gen

Get-ChildItem -Path $HOME -Filter *.ps1 -Include *.ps1 -Recurse | 
Where-Object { 
  ($_ | Get-AuthenticodeSignature).Status -eq 'NotSigned'
} |
Set-AuthenticodeSignature -Certificate $cert -WhatIf
