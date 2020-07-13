Import-Module Pester

Describe "Interaktive Demo" {
    It "ISE-Editor wird ausgef�hrt" {
        { Get-Process powershell_ise -ErrorAction Stop } | Should Not Throw
    }
}

Describe "Interaktive Demo" {
    It "gibt den Text 'Hello World' zur�ck (Gro�- und Kleinschreibung egal)" {
        "Hello World" | Should Be 'hello world'
    }
}

Describe "Interaktive Demo" {
    It "enth�lt das Wort 'world' in Kleinschreibung" {
        "Hello World" | Should MatchExactly 'world'
    }
}
