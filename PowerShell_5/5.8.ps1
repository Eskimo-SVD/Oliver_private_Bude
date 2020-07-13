# $cert muss bereits ein gültiges digitales Zertifikat enthalten (siehe Buch)
# entfernen Sie -whatIf, um die Signaturen tatsächlich einzufügen

Get-ChildItem -Path $HOME -Filter *.ps1 -Include *.ps1 -Recurse | 
Where-Object { 
  ($_ | Get-AuthenticodeSignature).Status -eq 'NotSigned'
} |
Set-AuthenticodeSignature -Certificate $cert -WhatIf
