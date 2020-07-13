Add-Type -AssemblyName PresentationFramework

function Start-InNewThread
{
  param
  (
    [ScriptBlock]$Code,
    
    [Hashtable]$Parameters = @{}
  )
  
  $powershell = [PowerShell]::Create()
  $action = {
   
    $status = $event.SourceEventArgs.InvocationStateInfo.State
    
    if ($status -eq 'Completed')
    {
      try
      {
        $powershell = $event.Sender
        $powershell.Runspace.Close()
        $powershell.Dispose()
        Unregister-Event -SourceIdentifier $event.SourceIdentifier 
      }
      catch
      {
        Write-Warning "$_"
      }
    }
  }
  
  $null = Register-ObjectEvent -InputObject $powershell -Action $action -EventName InvocationStateChanged 
  $null = $powershell.AddScript($Code)
  
  foreach($key in $Parameters.Keys)
  {
    $null = $powershell.AddParameter($key, $Parameters.$key)
  }
 
  $handle = $powershell.BeginInvoke()
}

$xaml = @"
<Window
 xmlns='http://schemas.microsoft.com/winfx/2006/xaml/presentation'
 Title='Hotfix Viewer' 
 MinWidth='300'
 Width='600'
 MinHeight='300' 
 Height = '300'>

<Grid Margin="5">
  <Grid.RowDefinitions>
      <RowDefinition Height="*"></RowDefinition>
      <RowDefinition Height="Auto"></RowDefinition>
  </Grid.RowDefinitions>

  <ListView Name="View1">
    <ListView.View>
      <GridView>
        <GridViewColumn Width="100" Header="KB" DisplayMemberBinding="{Binding HotfixID}"/>
        <GridViewColumn Width="150" Header="Typ" DisplayMemberBinding="{Binding Description}"/>
        <GridViewColumn Width="150" Header="Datum" DisplayMemberBinding="{Binding InstalledOn}"/>
        <GridViewColumn Width="150" Header="Verantwortlich" DisplayMemberBinding="{Binding InstalledBy}"/>
       </GridView>
    </ListView.View>
  </ListView>
  <StackPanel Grid.Row="1" Orientation="Horizontal" HorizontalAlignment="Right" VerticalAlignment="Bottom">
    <Button Name="butShow" Width="80" Height="30" Margin="5">Show</Button>
    <Button Name="butOK" Width="80" Height="30" Margin="5">OK</Button>
  </StackPanel>
</Grid>

</Window>
"@

$reader = [System.XML.XMLReader]::Create([System.IO.StringReader] $xaml)
$window = [System.Windows.Markup.XAMLReader]::Load($reader)


$buttonOK = $window.FindName('butOK')
$buttonShow = $window.FindName('butShow')

$code1 = { 
  param($Info)
  
  # ObservableCollection löschen
  $Info.Clear()
  Get-Hotfix | 
  # WICHTIG: mit Select-Object alle gewünschten Eigenschaften angeben:
  Select-Object -Property HotfixId, Description, InstalledBy, InstalledOn | 
  # Ergebnisse neu in ObservableCollection einfügen
  ForEach-Object { $null = $info.Add($_) }
}
$code2 = { $window.Close() }

# ObservableCollection als Parameter an Hintergrundthread übergeben:
$buttonShow.add_Click({ Start-InNewThread -Code $code1 -Parameters @{Info=$data}})

$buttonOK.add_Click($code2)

# eine leere ObservableCollection beschaffen
$data = New-Object System.Collections.ObjectModel.ObservableCollection[Object] 

# ObservableCollection threadsicher machen (erfordert .NET Framework 4.5)
$lock = 1
[Windows.Data.BindingOperations]::EnableCollectionSynchronization($data, $lock)

# als Datenquelle für das Grid setzen:
$view = $window.FindName('View1')
$view.ItemsSource = $data

$null = $window.ShowDialog()
