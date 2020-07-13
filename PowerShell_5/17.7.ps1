# wird beim Import des Moduls ausgeführt

# <hier könnten zunächst weitere Skripts dot-sourced geladen
# oder Funktionen definiert werden>

Write-Host 'Modul ist geladen.' -ForegroundColor Green

$MyInvocation.MyCommand.ScriptBlock.Module.OnRemove = {
    # wird beim Entfernen des Moduls ausgeführt
    Write-Host 'Modul ist wieder entfernt.' -ForegroundColor Red
}
