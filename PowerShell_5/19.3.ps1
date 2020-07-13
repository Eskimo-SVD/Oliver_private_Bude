$mySetting = @{}

function Set-SettingA
{
    param($NewValue)
    $mySetting.SettingA = $NewValue
}

function Set-SettingB
{
    param($NewValue)
    $mySetting.SettingB = $NewValue
}

function Get-Setting
{
  $mySetting
}
