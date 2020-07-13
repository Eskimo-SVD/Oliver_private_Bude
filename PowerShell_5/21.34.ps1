$stichtag = Get-Date -Hour 0 -Minute 0 -Second 0

# Scheife, die nur EINMAL l�uft:
$anmeldungen = do
{
  Get-EventLog -LogName Security -InstanceId 4624 |
  ForEach-Object {
    # wenn ein Eintrag empfangen wird, der VOR dem Stichtag liegt, 
    # abbrechen:
    if ($_.TimeGenerated -lt $Stichtag) { continue }
    # andernfalls Ergebnis zur�ckgeben:
    $_
  }
} while ($false)

$anmeldungen.Count
$anmeldungen | Out-GridView
