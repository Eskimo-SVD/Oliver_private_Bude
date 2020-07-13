$code = { 
    @{
        Name = 'Tobias'
        ID = $test
        Datum = Get-Date
    }
}

$test = 100

try
{
    $code.CheckRestrictedLanguage([String[]]@('Get-Date'), [String[]]@('test'), $null)
    & $code
}
catch
{
    Write-Warning "Unzulässig: $_"
}
