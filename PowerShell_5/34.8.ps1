class MyWebClient : System.Net.WebClient
{
  MyWebClient() : base() 
  {
    # bei SSL-Zertifikatfehlern trotzdem Webseite ansprechen
    [System.Net.ServicePointManager]::ServerCertificateValidationCallback = { $true }
    
    $proxy = [System.Net.WebRequest]::GetSystemWebProxy()
    $proxy.Credentials = [System.Net.CredentialCache]::DefaultCredentials
    $this.Proxy = $proxy
    $this.UseDefaultCredentials = $true
    $this.Proxy.Credentials = $this.Credentials
  }
}

$client = New-Object -TypeName MyWebClient
$client.DownloadString('http://www.tagesschau.de')
