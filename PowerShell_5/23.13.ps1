$computername = 'server02'

Connect-WSMan $computername
Get-ChildItem -Path "wsman:\$computername\plugin\*\Filename" |
      Where-Object Value -like '*pwrshplugin.dll' | ForEach-Object {Split-Path -Leaf $_.PSParentPath }
