$Path = "$env:temp\Testordner"
$existiert = Test-Path -Path $Path

if ($existiert -eq $false)
{
  $null = New-Item -Path $Path -ItemType Directory
  Write-Host 'Ordner neu angelegt'
}
else
{
  Write-Host "Ordner '$Path' existierte schon."
}
