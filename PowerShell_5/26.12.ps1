workflow Test-Workflow
{
    param
    (
        $Name
    )

    Get-Service -Name $Name
}

function Test-Function
{
    param
    (
        $Name
    )

    Get-Service -Name $Name
}

$dienstWorkflow = Test-Workflow -Name Spooler
$dienstFunktion = Test-Function -Name Spooler
