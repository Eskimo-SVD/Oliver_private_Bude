Import-Module Pester

Describe "Interaktive Demo" {
    It "Richtige Ausgabe" {
        { Get-Process powershell_ise -ErrorAction Stop } | Should Not Throw
        "Hello World" | Should Be 'hello world'
        "Hello World" | Should MatchExactly 'world'
    }
}
