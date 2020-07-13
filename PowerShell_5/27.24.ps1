#requires -Version 1

# Umgebungsvariablen im "Process"-Set
# (gelten nur für die aktuelle Anwendung und
# alle von ihr gestarteten Anwendungen)

# anlegen:
$env:NewVariable = 'test'

# lesen:
$env:NewVariable

# löschen:
# ACHTUNG: nicht $env:NewVariable angeben, sondern env:NewVariable
# andernfalls wird der INHALT der Variablen gelesen und dieser Pfad
# gelöscht!
Remove-Item -Path env:NewVariable

# Umgebungsvariablen im "User"-Set
# (gelten für den aktuellen Anwender)

# anlegen:
[Environment]::SetEnvironmentVariable('test', '100', 'user')

# lesen:
[Environment]::GetEnvironmentVariable('test', 'user')

# löschen:
[Environment]::SetEnvironmentVariable('test', '', 'user')


# Umgebungsvariablen im "Machine"-Set
# (gelten für alle Anwender, das Anlegen erfordert
# Administrator Rechte)

# anlegen:
[Environment]::SetEnvironmentVariable('test', '100', 'machine')

# lesen:
[Environment]::GetEnvironmentVariable('test', 'machine')

# löschen:
[Environment]::SetEnvironmentVariable('test', '', 'machine')
