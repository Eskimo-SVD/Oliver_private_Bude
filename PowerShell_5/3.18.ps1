#requires -Version 1

# neue User-Umgebungsvariable anlegen
[Environment]::SetEnvironmentVariable('test', '123', 'User')

# Umgebungsvariable wieder l�schen
[Environment]::SetEnvironmentVariable('test', $null, 'User')
