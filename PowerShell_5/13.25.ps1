function Get-HashTable
{
    param
    (
        [Parameter(Mandatory=$true)]
        $Path
    )

    # gesamten Text der Datei einlesen
    $code = Get-Content -Path $Path -Raw
    # eingelesener Text ist soll der Inhalt eines Hashtables sein
    $hashtablecode = "@{$code}"

    # aus diesem Code einen Skriptblock herstellen
    $scriptblock = [ScriptBlock]::Create($hashtablecode)
    try
    {
        # enth�lt der Skriptblock aktive Elemente?
        $scriptblock.CheckRestrictedLanguage([String[]]@(), [String[]]@(), $null)
        # nein, ausf�hren und Hashtable generieren
        & $scriptblock
    }
    catch
    {
        # ja, nicht ausf�hren
        Write-Warning "Gef�hrliche Inhalte in $Path"
    }
}
