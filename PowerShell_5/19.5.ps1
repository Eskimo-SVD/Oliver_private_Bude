$info = 'Undefined'

function Set-Value
{
    param($NewValue)

    $script:info = $NewValue
}

function Get-Value
{
    "Wert ist $info"
}
