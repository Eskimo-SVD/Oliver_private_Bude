workflow Test-Workflow
{
    $wert = 1
    sequence 
    {
        $wert

        sequence
        {
            $wert
        }
    }
}
