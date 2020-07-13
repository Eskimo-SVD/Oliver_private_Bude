$operator = New-ADUser -Name TestOperator -AccountPassword $password -PassThru
Enable-ADAccount -Identity $operator

$normaluser = New-ADUser -Name Normaluser -AccountPassword $password -PassThru
Enable-ADAccount -Identity $normaluser


Add-ADGroupMember -Identity $jeaAdmin -Members $operator
