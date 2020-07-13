Configuration CreateTextFileServer 
{
  Import-DscResource -ModuleName 'PSDesiredStateConfiguration' 
     
  File TestFile
  {
    DestinationPath = 'C:\DSCWaitFor\test.txt'
    Contents = 'anderer beliebiger Inhalt'
  }
}

CreateTextFileServer -OutputPath c:\DSCWaitFor
