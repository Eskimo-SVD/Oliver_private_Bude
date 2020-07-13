Import-Module Pester

Describe "Interaktive Demo" {
    It "Interaktive Demo" {
        { Get-Process powershell_ise -ErrorAction Stop } | Should Not Throw
    }
}
