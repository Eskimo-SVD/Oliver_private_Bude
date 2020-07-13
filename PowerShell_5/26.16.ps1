function Get-RemoteService1
{
    # Invoke-Command führt beliebigen PowerShell-Code auf einem
    # lokalen oder Remote-System aus
    Invoke-Command { Get-Service } -ComputerName dell1
}

Workflow Get-RemoteService2
{
    # InlineScript verhält sich wie Invoke-Command
    InlineScript { Get-Service } -PSComputerName dell1
}

Workflow Get-RemoteService3
{
    # ein Workflow kann insgesamt lokal oder remote ausgeführt werden
    # wenn der Parameter -PSComputerName beim Aufruf verwendet wird
    # das InlineScript wird dann auf demselben Computer ausgeführt wie
    # der Workflow, sofern es nicht selbst -PSComputerName festlegt
    InlineScript { Get-Service } 
}

Workflow Get-RemoteService4
{
    # Get-Service ist ein unterstützes Cmdlet und kann deshalb auch
    # ohne InlineScript direkt ausgeführt werden
    Get-Service 
}

$a = Get-RemoteService1
$b = Get-RemoteService2
$c = Get-RemoteService3 -PSComputerName dell1
$d = Get-RemoteService4 -PSComputerName dell1
