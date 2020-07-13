Configuration TextFile
{
  Import-DscResource -ModuleName 'PSDesiredStateConfiguration'            
  File TestFile
  {
    DestinationPath = 'C:\TextFile\test.txt'
    Contents = 'beliebiger Inhalt'
  }
}
TextFile -OutputPath c:\TextFile
Publish-DscConfiguration -Path c:\TextFile -Verbose
