function Limit-Runspace
{
  ... (abgek�rzt, hier muss die Funktion Limit-Runspace eingef�gt werden)
}

function Test-WMI
{
  Get-WMIObject -Class Win32_BIOS
}


Limit-Runspace -AllowedCommands Test-WMI
