Get-Content $env:windir\windowsupdate.log -Encoding UTF8 |
    Where-Object { $_ -like '*successfully installed*' } |
    ForEach-Object { ($_ -split 'following update: ')[-1] }
