function Test-Function
{
    Get-ChildItem -Path $env:windir\system32 |
      Select-Object { $_.FullName }
}

workflow Test-Workflow
{
    Get-ChildItem -Path $env:windir\system32 |
      Select-Object { $_.FullName }
}
