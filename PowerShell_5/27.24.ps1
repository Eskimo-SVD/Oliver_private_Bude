#requires -Version 1

# Umgebungsvariablen im "Process"-Set
# (gelten nur f�r die aktuelle Anwendung und
# alle von ihr gestarteten Anwendungen)

# anlegen:
$env:NewVariable = 'test'

# lesen:
$env:NewVariable

# l�schen:
# ACHTUNG: nicht $env:NewVariable angeben, sondern env:NewVariable
# andernfalls wird der INHALT der Variablen gelesen und dieser Pfad
# gel�scht!
Remove-Item -Path env:NewVariable

# Umgebungsvariablen im "User"-Set
# (gelten f�r den aktuellen Anwender)

# anlegen:
[Environment]::SetEnvironmentVariable('test', '100', 'user')

# lesen:
[Environment]::GetEnvironmentVariable('test', 'user')

# l�schen:
[Environment]::SetEnvironmentVariable('test', '', 'user')


# Umgebungsvariablen im "Machine"-Set
# (gelten f�r alle Anwender, das Anlegen erfordert
# Administrator Rechte)

# anlegen:
[Environment]::SetEnvironmentVariable('test', '100', 'machine')

# lesen:
[Environment]::GetEnvironmentVariable('test', 'machine')

# l�schen:
[Environment]::SetEnvironmentVariable('test', '', 'machine')
