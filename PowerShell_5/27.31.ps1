configuration Defender
{
  Import-DscResource -ModuleName xDefender
  node Localhost
  {
    xMpPreference Test1
    {
      Name = 'MyPreferences1'
      CheckForSignaturesBeforeRunningScan = $True
      HighThreatDefaultAction = 'Clean'
    }   
  }
}
