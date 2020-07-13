$shareklasse = [wmiclass] XE "[wmiclass]" '\\storage1\root\cimv2:Win32_Share'
$pfad = 'C:\'
$name = 'serviceshare'
$type = 0
$maximumallowed = 5
$description = 'Interner Share für Wartungsaufgaben'
$shareklasse.Create($pfad, $Name, $Type, $MaximumAllowed, $Description).ReturnValue
