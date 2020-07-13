#requires -Version 3

# Hashtable erstellen und Spaltendefinition festlegen:
$LängeMB = @{}
$LängeMB.Name='Length (MB)'
$LängeMB.Expression=
{ 
  # Wenn das Objekt kein Ordner ist...
  If ($_.PSIsContainer -eq $false) 
  { 
    # ...Length als MB ausgeben:
    '{0:0.00} MB' -f ($_.Length/1MB) 
  } 
} 

Get-ChildItem -Path $env:windir -File | 
  Select-Object -Property Mode, LastWriteTime, $LängeMB, Name
