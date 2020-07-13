# Quelle und Ziel angeben
$archive = Join-Path -Path $env:temp -ChildPath winScripts.zip
$target = Join-Path -Path $env:temp -ChildPath WinScriptsDSCManual

# DSC-Ressource finden
$resource = Get-DscResource -Name Archive
# DSC-Ressource als Modul laden
$module = import-module $resource.Path -PassThru

# Variable in Modul nachtr�glich �ndern
# (die Cache-Variable zeigt auf einen gesch�tzten System-Ordner;
# damit die Ressource ohne Adminrechte aufrufbar wird, muss der
# Cache-Ordner in einen Bereich verlegt werden, der keine
# Adminrechte erfordert)
. $module { $CacheLocation = Join-Path -Path $env:temp -ChildPath ArchiveCache }

# DSC-Ressource aufrufen (hei�t immer Set-TargetResource)
Set-TargetResource -Path $archive -Destination $target -Ensure Present -Force $true -Credential (Get-Credential)

# Targetordner im Explorer �ffnen
explorer $target
