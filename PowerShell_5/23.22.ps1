# Member des Dienstobjekts lokal und remote abrufen:
$lokal = Get-Service -Name Spooler |
    Get-Member | 
    Add-Member -MemberType NoteProperty -Name 'Origin' -Value 'local' -PassThru

$remote = Invoke-Command { Get-Service -Name Spooler } -Computername dell1 | 
    Get-Member | 
    Add-Member -MemberType NoteProperty -Name 'Origin' -Value 'remote' -PassThru

# Namen der Member vergleichen:
Compare-Object -Reference $lokal -Difference $remote -Property Name -PassThru |
  Sort-Object -Property Origin, Name |
  Select-Object -Property Origin, Name, MemberType, Definition
