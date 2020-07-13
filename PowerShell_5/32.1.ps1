$info = [Ordered]@{
    'Pester vorhanden' = (Get-Module -Name Pester -ListAvailable) -ne $null
    Version = (Get-Module -Name Pester -ListAvailable).Version
    'Aktuelle Version' = (Find-Module -Name Pester).Version
}

New-Object -TypeName PSObject -Property $info
