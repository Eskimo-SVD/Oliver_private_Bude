function Test-ReturnValue
{
    'halli' | Write-Output
    'hallo' | Write-Output
    return
    'hall�le' | Write-Output
}
