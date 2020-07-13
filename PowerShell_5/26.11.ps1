workflow Test-Workflow
{
    param
    (
        $EineInformation
    )

    "Parameter: $EineInformation"
    'Variable $text: ' + $Text
}

function Test-Function
{
    param
    (
        $EineInformation
    )

    "Parameter: $EineInformation"
    'Variable $text: ' + $Text
}

$Text = "Hallo!"
