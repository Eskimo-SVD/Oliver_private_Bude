Configuration changeSystemOwner
{
    Import-DscResource –ModuleName xConfigPersonalData

    Node 'localhost'
    {
        xSetOwnerInfo OwnerConfig
        {
            RegisteredOwner = 'Dr. Tobias Weltner'
            RegisteredOrganization = 'powertheshell.com'
            Ensure = 'Present'
        }
    }
}

$file = changeSystemOwner -OutputPath c:\myDSCDefinitions
