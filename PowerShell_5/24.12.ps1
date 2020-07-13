# Session verwenden
$session = New-PSSession -ComputerName DC01 -ConfigurationName ADAdmin

# Inhalt als Modul "ADAdmin" exportieren
Export-PSSession -OutputModule ADAdmin -CommandName * -CommandType Cmdlet, Function -Session $session -Force 

# Session verwerfen
Remove-PSSession $session
