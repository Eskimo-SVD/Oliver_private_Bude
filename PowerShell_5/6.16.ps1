$zeilen = Get-Content $env:windir\windowsupdate.log -Encoding UTF8 -ReadCount 0
foreach ($zeile in $zeilen)
{
 if ($zeile -like '*successfully installed*')
 { ($zeile -split 'following update: ')[-1] }
}
