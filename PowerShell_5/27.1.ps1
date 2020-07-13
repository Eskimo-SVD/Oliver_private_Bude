Configuration createDSCFolder
{
    Import-DscResource –ModuleName 'PSDesiredStateConfiguration'

    Node "localhost"
    {
        File createFolder
        {
            Type = 'Directory'
            Ensure = 'Present'
            DestinationPath = 'c:\newfolderDSC'
            Force = $true
        }
    }
}

$file = createDSCFolder -OutputPath c:\myDSCDefinitions
