$here = Split-Path -Parent $MyInvocation.MyCommand.Path
$sut = (Split-Path -Leaf $MyInvocation.MyCommand.Path) -replace '\.Tests\.', '.'
. "$here\$sut"

Describe 'New-File' {
    It 'löst keinen Fehler aus' {
      { New-File 'TestDrive:\somefolder\anotherfolder\file.txt' } | Should Not Throw
    }
    It 'legt eine neue Datei mit notwendigen Ordnern an' {
      New-File 'TestDrive:\somefolder\anotherfolder\file.txt' | Should Exist 'TestDrive:\somefolder\anotherfolder\file.txt'
    }
    It 'ruft eine vorhandene Datei ab' {
      New-File 'TestDrive:\somefolder\anotherfolder\file.txt' | Should Not BeNullOrEmpty
    }
}
