workflow Test-Workflow
{
    # bei der Zuweisung einer Variable auf oberster Workflow-Ebene
    # darf workflow: nicht eingesetzt werden!
    $wert = 1
    sequence 
    {
        $workflow:wert
        $workflow:wert += 1

        sequence
        {
            $workflow:wert
            $workflow:wert++
        }
    }
    $workflow:wert
}
