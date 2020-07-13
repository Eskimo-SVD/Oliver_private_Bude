configuration ConfigWebsite
{
  # Module für alle verwendeten Ressourcen importieren
  Import-DscResource -Module xWebAdministration, PSDesiredStateConfiguration
 
  # Betroffene Computer aus ConfigurationData ermitteln
  Node $AllNodes.where{$_.Role -eq "Web"}.NodeName
  {
    
    # Existierende Webseite stoppen
    xWebsite DefaultSite
    {
      Ensure          = "Present"
      Name            = "Default Web Site"
      State           = "Stopped"
      PhysicalPath    = $Node.DefaultWebSitePath
      DependsOn       = "[WindowsFeature]IIS"
    }
    
    # IIS-Rolle installieren
    WindowsFeature IIS
    {
      Ensure          = "Present"
      Name            = "Web-Server"
    }
 
    # .NET 4.5 installieren
    WindowsFeature AspNet45
    {
      Ensure          = "Present"
      Name            = "Web-Asp-Net45"
    }
 
    # Webseiteninhalt kopieren
    File WebContent
    {
      Ensure          = "Present"
      SourcePath      = $Node.SourcePath
      DestinationPath = $Node.DestinationPath
      Recurse         = $true
      Type            = "Directory"
      DependsOn       = "[WindowsFeature]AspNet45"
    }      
 
    # neue Webseite generieren
    xWebsite NewWebSite
    {
      Ensure          = "Present"
      Name            = $Node.WebsiteName
      State           = "Started"
      PhysicalPath    = $Node.DestinationPath
      DependsOn       = "[File]WebContent"
    }
  }
}

ConfigWebsite -ConfigurationData C:\webserverConfig\webpts.psd1 -OutputPath c:\DSCConfigsWebServer
ConfigWebsite -ConfigurationData C:\webserverConfig\webpts.psd1 -OutputPath c:\DSCConfigsWebServer
