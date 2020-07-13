Import-Module Pester

Describe 'Testet Voraussetzungen' {
    It 'Notwendige Datei vorhanden' -TestCases @{file = "$env:windir\explorer.exe"},
        @{file = "$env:windir\system32\Windowspowershell"},
        @{file = "$home\Documents\WindowsPowerShell\Modules"} -Test {
        param ([string]$file)
 
        $file | Should Exist
    }
}
