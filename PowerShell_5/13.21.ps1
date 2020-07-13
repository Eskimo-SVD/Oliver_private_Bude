$code = {
    $ergebnis = Get-Service | Where-Object Status -eq Running
}

$code.Ast.FindAll( { $true }, $true) |
  Add-Member -Member ScriptProperty -Name Type -Value { $this.GetType().Name } -PassThru
