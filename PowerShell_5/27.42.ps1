Configuration CreateTextFileClient
{
  Import-DscResource -ModuleName 'PSDesiredStateConfiguration'
  WaitForAny WaitForB
  {
    ResourceName = '[File]CreateTextFileServer'
    NodeName = 'SYSTEM_B'
    RetryIntervalSec = 30
    RetryCount = 30
  }
  File TestFile
  {
    DestinationPath = 'C:\DSCWaitFor\test.txt'
    Contents = 'beliebiger Inhalt'
  }
}

CreateTextFileClient -OutputPath c:\DSCWaitFor
