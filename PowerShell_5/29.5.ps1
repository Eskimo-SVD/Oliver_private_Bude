$server1 = '\\storage1'
$server2 = '\\powershellpc'

$fileList1 = Get-ChildItem $server1\c$\windows\system32\*.dll |
  Sort-Object -Property Name |
  # eine neue Eigenschaft namens "ComputerName" anf�gen und den Herkunftsserver darin angeben:
  Add-Member -MemberType NoteProperty -Name ComputerName -Value $server1 -PassThru |
  Add-Member -MemberType ScriptProperty -Name Version -Value { $this.VersionInfo.ProductVersion } -PassThru

$fileList2 = Get-ChildItem $server2\c$\windows\system32\*.dll |
  Sort-Object -Property Name |
  # eine neue Eigenschaft namens "ComputerName" anf�gen und den Herkunftsserver darin angeben:
  Add-Member -MemberType NoteProperty -Name ComputerName -Value $server2 -PassThru |
  Add-Member -MemberType ScriptProperty -Name Version -Value { $this.VersionInfo.ProductVersion } -PassThru

# Unterschiedliche Dateien finden (basierend auf "Name" und "Length") und Objekte mit -PassThru
# weitergeben:
Compare-Object -ReferenceObject $fileList1 -DifferenceObject $fileList2 -Property Name, Version -PassThru |
  Sort-Object -Property Name |
  Select-Object -Property ComputerName, Name, Version |
  Out-GridView
