$here = Split-Path -Parent $MyInvocation.MyCommand.Path
$sut = (Split-Path -Leaf $MyInvocation.MyCommand.Path) -replace '\.Tests\.', '.'
. "$here\$sut"

Describe 'New-LocalUserAccount' {
    It "Lokales Benutzerkonto 'testaccount' existiert noch nicht" {
      {
        # Testkonto versuchsweise abrufen. Wenn es nicht existiert,
        # kommt es zu einem Fehler. Ein Fehler ist also erwartet:
        $ErrorActionPreference = 'Stop'
        net user Testaccount 2>&1 
      }| Should Throw
    }
    It "Neues Benutzerkonto namens 'Testaccount' anlegen" {
      { 
        # Konto anlegen. Das Konto existiert danach tatsächlich.
        New-LocalUserAccount -Name Testaccount 
      } | Should Not Throw
      
      {
        # Konto wird gesucht und sollte jetzt existieren:
        $ErrorActionPreference = 'Stop'
        net user Testaccount 2>&1 
      }| Should Not Throw
      
      # Aufräumungsarbeiten: Das Testkonto muss wieder entfernt werden:
      $null =  net user Testaccount /DELETE
    }
}
