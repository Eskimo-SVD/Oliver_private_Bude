$befehl = { powercfg.exe /LIST }

$remotecode = 
{ 
    param($Code)
    $job = Start-Job ([ScriptBlock]::Create($Code)) -Name Aufgabe1
    $null = Wait-Job $job 
    Receive-Job -Name Aufgabe1
    Remove-Job -Name Aufgabe1
}  

Invoke-Command -ComputerName dell1 -ArgumentList $befehl -ScriptBlock $remotecode
