function Get-SoftwareUpdate
{
    $Filter = @{
      ProviderName="Microsoft-Windows-WindowsUpdateClient"
      ID=19
    }

  Get-WinEvent -FilterHashtable $filter |
    ForEach-Object {
      $rv = $_ | 
  Select-Object -Property TimeCreated, Name, Activity, Status, UserId, TaskDisplayName
      $rv.Name = $_.Properties[0].Value
      $rv.Activity = $_.KeywordsDisplayNames[0]
      $rv.Status = $_.KeywordsDisplayNames[1]
      $rv
    }
  
}
