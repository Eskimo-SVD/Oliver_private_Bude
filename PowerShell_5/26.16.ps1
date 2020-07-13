function Get-RemoteService1
{
    # Invoke-Command f�hrt beliebigen PowerShell-Code auf einem
    # lokalen oder Remote-System aus
    Invoke-Command { Get-Service } -ComputerName dell1
}

Workflow Get-RemoteService2
{
    # InlineScript verh�lt sich wie Invoke-Command
    InlineScript { Get-Service } -PSComputerName dell1
}

Workflow Get-RemoteService3
{
    # ein Workflow kann insgesamt lokal oder remote ausgef�hrt werden
    # wenn der Parameter -PSComputerName beim Aufruf verwendet wird
    # das InlineScript wird dann auf demselben Computer ausgef�hrt wie
    # der Workflow, sofern es nicht selbst -PSComputerName festlegt
    InlineScript { Get-Service } 
}

Workflow Get-RemoteService4
{
    # Get-Service ist ein unterst�tzes Cmdlet und kann deshalb auch
    # ohne InlineScript direkt ausgef�hrt werden
    Get-Service 
}

$a = Get-RemoteService1
$b = Get-RemoteService2
$c = Get-RemoteService3 -PSComputerName dell1
$d = Get-RemoteService4 -PSComputerName dell1
