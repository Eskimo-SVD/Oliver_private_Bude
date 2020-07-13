Register-EngineEvent -SourceIdentifier VariableChange -Action { Write-Host ($event.MessageData) -Fore 'DarkGreen' -Back 'White'} | Out-Null

function Monitor-Variable($variablename) {
  $action = '$true; New-Event -SourceIdentifier VariableChange -MessageData "Neuer Wert $_ für Variable {0}"' -f $variablename
  (Get-Variable $variablename).Attributes.Add((New-Object System.Management.Automation.ValidateScriptAttribute ([scriptblock]::Create($action))))
}
