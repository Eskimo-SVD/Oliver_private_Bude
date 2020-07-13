$code = { 
    @{
        Name = 'Tobias'
        ID = 12
    }
}


$code.CheckRestrictedLanguage([String[]]'', [String[]]'', $null)

& $code
