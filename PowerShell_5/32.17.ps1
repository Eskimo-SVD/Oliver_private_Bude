$here = Split-Path -Parent $MyInvocation.MyCommand.Path
$sut = (Split-Path -Leaf $MyInvocation.MyCommand.Path) -replace '\.Tests\.', '.'
. "$here\$sut"

Describe 'Remove-LogFile' {
  Mock Remove-Item { <# es wird nicht wirklich gelöscht #> }
  Mock Test-Path { $true } -ParameterFilter { $Path -and $Path -eq "$env:temp\sample.txt" }
  Mock Test-Path { $false } 
  It 'existierende Datei löschen' {
    Remove-Logfile -Path "$env:temp\sample.txt" | Should BeNullOrEmpty
  }
  It 'nicht vorhandene Datei liefert Fehler' {
    { Remove-LogFile -Path c:\doesnotexist.txt } | Should Throw
  }
}
