$serviceAdmins = New-ADGroup -Name JEA_Service -GroupScope DomainLocal -PassThru
$infoAdmins = New-ADGroup -Name JEA_Info -GroupScope DomainLocal -PassThru

$password = ConvertTo-SecureString -String P@ssw0rd -AsPlainText -Force

$serviceUser = New-ADUser -Name ServiceUser -AccountPassword $password -PassThru
Enable-ADAccount -Identity $serviceUser

$infoUser = New-ADUser -Name InfoUser -AccountPassword $password -PassThru
Enable-ADAccount -Identity $infoUser


Add-ADGroupMember -Identity $serviceAdmins -Members $serviceUser
Add-ADGroupMember -Identity $infoAdmins -Members $infoUser
