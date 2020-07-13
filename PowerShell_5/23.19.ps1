function Limit-Runspace
{
  ... (abgekürzt, hier muss die Funktion Limit-Runspace eingefügt werden)
}

function Test-WMI
{
  Get-WMIObject -Class Win32_BIOS
}


Limit-Runspace -AllowedCommands Test-WMI
