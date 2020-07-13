function Get-NestLevel
{
    try
    {
    $i = 0
    do 
    {
        $i++
        $null = Get-Variable -Name host -Scope $i
    } while ($true)
    }
    catch
    {
        $i-2
    }
}

function Test-NestLevel
{
    Get-NestLevel
}

Get-NestLevel 
Test-NestLevel
