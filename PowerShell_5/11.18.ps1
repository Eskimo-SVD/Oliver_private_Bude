# Anmeldeinformationen festlegen:
$WMIOptionen = New-Object System.Management.ConnectionOptions
$anmeldung = Get-Credential
$WMIOptionen.SecurePassword = $anmeldung.Password
$WMIOptionen.UserName = $anmeldung.UserName

$path = '\\storage1\root\cimv2:Win32_Share'
$scope = New-Object System.Management.ManagementScope($path, $WMIOptions)
$scope.Connect()

$optionen = New-Object System.Management.ObjectGetOptions

# Freigabe einrichten:
$shareklasse = New-Object System.Management.ManagementClass($scope, $path, $optionen)
$pfad = 'C:\'
$name = 'serviceshare_neu'
$type = 0
$maximumallowed = 5
$description = 'Interner Share für Wartungsaufgaben'
$shareklasse.Create($pfad, $Name, $Type, $MaximumAllowed, $Description).ReturnValue
