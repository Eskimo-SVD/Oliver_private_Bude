$code = { 
    @{
        Name = 'Tobias'
        ID = 12
        Datum = Get-Date
    }
}


$code.CheckRestrictedLanguage([String[]]'', [String[]]'', $null)

& $code
