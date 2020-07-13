# Kultur auf Spanisch festlegen:
$options = New-PSSessionOption -Culture "es-es"
$session = New-PSSession -ComputerName dell1 -SessionOption $options
Invoke-Command $session { Get-Date | Out-String }
