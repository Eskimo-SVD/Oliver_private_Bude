configuration Defender
{
  Import-DscResource -ModuleName xDefender
  node Localhost
  {
    xMpPreference SignatureSetting
    {
      Name = 'SignatureCheck'
      CheckForSignaturesBeforeRunningScan = $True
    } 

    xMpPreference HighThreatAction
    {
      Name = 'HighThreadAction'
      HighThreatDefaultAction = 'Clean'
    }     
  }
}
