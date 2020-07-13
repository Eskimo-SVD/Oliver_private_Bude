function Find-Enum
{
    param
    (
        $Value = '*',
        $Name = '*',
        [Switch]
        $All
    )

    $default = 'CommonLanguageRuntimeLibrary', 'Microsoft.CSharp.dll',
      'Microsoft.Management.Infrastructure.dll', 'Microsoft.PowerShell.Commands.Management.dll',
      'Microsoft.PowerShell.Commands.Utility.dll', 'System.Configuration.dll',
      'System.Configuration.Install.dll', 'System.Core.dll', 'System.Data.dll',
      'System.DirectoryServices.dll', 'System.dll', 'System.Management.Automation.dll',
      'System.Management.dll', 'System.Transactions.dll', 'System.Xml.dll'

[AppDomain]::CurrentDomain.GetAssemblies() |
  Where-Object { $All -or ($default -contains $_.ManifestModule) } |
  ForEach-Object { try { $_.GetExportedTypes() } catch {} } |
  Where-Object { $_.IsEnum } |
  Where-Object { $_.Name -like $Name } |
  Sort-Object -Property Name |
  ForEach-Object {
    $rv = $_ | Select-Object -Property Name, Values, Source
    $rv.Name = '[{0}]' -f $_.FullName
    $rv.Source = $_.Module.ScopeName
    $rv.Values = [System.Enum]::GetNames($_) -join ', '
    $rv
  } |
  Where-Object { @($_.Values -split ', ') -like $Value }
}
