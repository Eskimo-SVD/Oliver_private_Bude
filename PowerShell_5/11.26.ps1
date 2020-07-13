$shell = New-Object -ComObject Wscript.Shell

$StartUser = $shell.SpecialFolders.Item('StartMenu')
$StartAll = "$env:ALLUSERSPROFILE\Windows\Startmenü"

Get-ChildItem -Path $StartUser, $StartAll -Filter *.lnk -Recurse -ErrorAction SilentlyContinue | 
ForEach-Object {
  $lnkfile = $shell.CreateShortcut($_.FullName)
  New-Object -TypeName PSObject -Property @{
      Hotkey =  $lnkfile.Hotkey
      Name = $_.Name
  }
}
