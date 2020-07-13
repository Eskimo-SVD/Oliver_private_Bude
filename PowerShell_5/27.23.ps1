function Set-ArchiveResource
{
    param
    (
        [parameter(Mandatory = $true)]
        [ValidateNotNullOrEmpty()]
        [string] $Path,
        
        [parameter(Mandatory = $true)]
        [ValidateNotNullOrEmpty()]
        [string] $Destination,
        
        [Switch] $Validate,
        
        [ValidateSet("", "SHA-1", "SHA-256", "SHA-512", "CreatedDate", "ModifiedDate")]
        [string] $Checksum,

        [Switch] $Force,
        
        [pscredential] $Credential,

        [ValidateSet("Present", "Absent")]
        [string] $Ensure = "Present"
    )

# DSC-Ressource finden
$ProgressPreference = 'SilentlyContinue'

#$resource = Get-DscResource -Name Archive 
# DSC-Ressource als Modul laden
#$module = import-module $resource.Path -PassThru
$module = Import-Module -PassThru -Name "$PSHOME\Modules\PsDesiredStateConfiguration\DSCResources\MSFT_ArchiveResource\MSFT_ArchiveResource.psm1"
# Variable in Modul nachträglich ändern
# (die Cache-Variable zeigt auf einen geschützten System-Ordner;
# damit die Ressource ohne Adminrechte aufrufbar wird, muss der
# Cache-Ordner in einen Bereich verlegt werden, der keine
# Adminrechte erfordert)
. $module { $CacheLocation = Join-Path -Path $env:temp -ChildPath ArchiveCache }

# DSC-Ressource aufrufen (heißt immer Set-TargetResource)
Set-TargetResource @PSBoundParameters

# Modul entladen
Remove-Module $module

# Targetordner im Explorer öffnen
explorer $Destination
}

# Quelle und Ziel angeben
$archive = Join-Path -Path $env:temp -ChildPath winScripts.zip
$target = Join-Path -Path $env:temp -ChildPath WinScriptsDSCManual

Set-ArchiveResource -Path $archive -Destination $target
