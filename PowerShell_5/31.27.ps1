Add-Type -AssemblyName PresentationFramework

$xaml = @"
<Window
 xmlns='http://schemas.microsoft.com/winfx/2006/xaml/presentation'
 Title='Process Viewer' 
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
# Hotfixes abrufen und anzeigen
  [Windows.Input.Mouse]::OverrideCursor = 'Wait'
  $view = $window.FindName('View1')
  $view.ItemsSource = @(Get-Hotfix)
  [Windows.Input.Mouse]::OverrideCursor = $null
}

$code2 = { $window.Close() }

$buttonShow.add_Click($code1)
$buttonOK.add_Click($code2)


$null = $window.ShowDialog()
