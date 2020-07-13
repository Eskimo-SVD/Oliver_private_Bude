$result = [Ordered]@{}

foreach($user in 'AllUsers', 'CurrentUser')
{
    foreach($scope in 'AllHosts', 'CurrentHost')
    {
        $name = "$user$scope"
        $result.$name = Test-Path -Path $profile.$name
    }
}

New-Object -TypeName PSObject -Property $result
