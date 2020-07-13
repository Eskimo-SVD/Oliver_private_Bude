workflow Test-Workflow
{
    $wert = 1
    sequence 
    {
        $wert
        $workflow:wert += 1

        sequence
        {
            $wert
            $workflow:wert++
        }
    }
    $wert
}
