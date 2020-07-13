function ConvertTo-AbsoluteURL 
{ 
  param
  (
    [Parameter(Mandatory = $true, ValueFromPipeline=$true)]
    [string]
    $URL,
        
    [Parameter(Mandatory = $true)]
    [string]
    $WebsiteURL
  )

  begin
  {
    if ($WebsiteURL -notlike 'http*')
    {
      $WebsiteURL = "http://$WebsiteURL"
    }
    
    # Schr�gstriche normalisieren
    $WebsiteURL = $WebsiteURL.Replace('\', '/').TrimEnd('/')
    
    # Wurzel der Webseite ermitteln
    $WebsiteURL = ($WebsiteURL -split '(?<=[^/])/')[0,1] -join '/' 
  }
  
  process
  {
    $URL = $URL.Replace('\', '/').TrimStart('/')
    
    # wenn die URL nicht mit "http" beginnt...
    if ($URL -notlike 'http*')
    {
      # ...dann eine absolute URL daraus machen, indem die 
      # Adresse der Webseite vorangestellt wird
      return "$WebsiteURL/$URL"
    }
    else
    {
      # andernfalls unver�ndert zur�ckgeben
      return $URL
    }
  }
}
