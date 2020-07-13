$here = Split-Path -Parent $MyInvocation.MyCommand.Path
$sut = (Split-Path -Leaf $MyInvocation.MyCommand.Path) -replace '\.Tests\.', '.'
. "$here\$sut"

Describe 'Restart-InactiveComputer' {

  Mock Restart-Computer { <# Neustart wird nur simuliert #> }

  Context 'Computer sollte neu starten' {
    It 'Neustart, wenn niemand angemeldet ist' {

      Mock Get-Process {}

      Restart-InactiveComputer 

      Assert-MockCalled Restart-Computer -Exactly 1
    }
  }
    
  Context 'Computer sollte NICHT neu starten' {
    It 'Kein Neustart bei angemeldeten Benutzern' {

      Mock Get-Process { 'irgendetwas liefern' }

      Restart-InactiveComputer

      Assert-MockCalled Restart-Computer -Exactly 0
    }
  }
}
