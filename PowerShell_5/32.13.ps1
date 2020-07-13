Import-Module Pester

Describe "Interaktive Demo" {
    It "ISE-Editor wird ausgeführt" {
        { Get-Process powershell_ise -ErrorAction Stop } | Should Not Throw
    }
}

Describe "Interaktive Demo" {
    It "gibt den Text 'Hello World' zurück (Groß- und Kleinschreibung egal)" {
        "Hello World" | Should Be 'hello world'
    }
}

Describe "Interaktive Demo" {
    It "enthält das Wort 'world' in Kleinschreibung" {
        "Hello World" | Should MatchExactly 'world'
    }
}
