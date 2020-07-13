Get-WmiObject -Class Win32_Process | Foreach-Object {
    $owner = $_.GetOwner()
    if ($owner.ReturnValue -eq 0)
    {
        $owner = '{0}\{1}' -f $owner.Domain, $owner.User
    }
    else
    {
        $owner = $null
    }
    $_ | Add-Member -MemberType NoteProperty -Name Owner -Value $owner -PassThru
} | Select-Object -Property Name, Owner, ProcessId |
Out-GridView
