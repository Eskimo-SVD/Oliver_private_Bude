# wird beim Import des Moduls ausgef�hrt

# <hier k�nnten zun�chst weitere Skripts dot-sourced geladen
# oder Funktionen definiert werden>

Write-Host 'Modul ist geladen.' -ForegroundColor Green

$MyInvocation.MyCommand.ScriptBlock.Module.OnRemove = {
    # wird beim Entfernen des Moduls ausgef�hrt
    Write-Host 'Modul ist wieder entfernt.' -ForegroundColor Red
}
