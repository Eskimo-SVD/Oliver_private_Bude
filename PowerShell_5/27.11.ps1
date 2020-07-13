# neue Website auf zwei Webservern einrichten:

@{
  AllNodes = @(
    @{
      # diese Angaben gelten f�r alle Computer
      NodeName           = "*"
      WebsiteName        = "powertheshell.com"
      SourcePath         = "C:\PTS\"
      DestinationPath    = "C:\inetpub\PowerTheShell"
      DefaultWebSitePath = "C:\inetpub\wwwroot"
    },
 
    @{
      NodeName           = "WebServer1.PTS.com"
      Role               = "Web"
    },
 
    @{
      NodeName           = "WebServer2.PTS.com"
      Role               = "Web"
    }
  )
}
