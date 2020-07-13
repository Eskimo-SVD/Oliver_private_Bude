Add-Type -AssemblyName PresentationFramework

$xaml = @"
<Window
 xmlns='http://schemas.microsoft.com/winfx/2006/xaml/presentation'
 Title='Process Viewer' 
 MinWidth='300'
 MinHeight='300' 
 Height = '600'>

<Grid Margin="5">
  <Grid.RowDefinitions>
      <RowDefinition Height="*"></RowDefinition>
      <RowDefinition Height="Auto"></RowDefinition>
  </Grid.RowDefinitions>

  <ListView Name="View1">
    <ListView.View>
      <GridView>
        <GridViewColumn Width="140" Header="Name" DisplayMemberBinding="{Binding Name}"/>
        <GridViewColumn Width="350" Header="Fenstertitel" DisplayMemberBinding="{Binding MainWindowTitle}"/>
        <GridViewColumn Width="140" Header="Beschreibung" DisplayMemberBinding="{Binding Description}"/>
        <GridViewColumn Width="100" Header="Hersteller" DisplayMemberBinding="{Binding Company}"/>
      </GridView>
    </ListView.View>
  </ListView>
  <StackPanel Grid.Row="1" Orientation="Horizontal" HorizontalAlignment="Right" VerticalAlignment="Bottom">
    <Button Name="butStop" Width="80" Height="30" Margin="5">Stop</Button>
    <Button Name="butCancel" Width="80" Height="30" Margin="5">Cancel</Button>
  </StackPanel>
</Grid>

</Window>
"@

$reader = [System.XML.XMLReader]::Create([System.IO.StringReader] $xaml)
$window = [System.Windows.Markup.XAMLReader]::Load($reader)

# Liste füllen
$view = $window.FindName('View1')

$view.ItemsSource = @(Get-Process | Where-Object { $_.MainWindowTitle }) | 
# MINDESTENS die Properties auswählen, die angezeigt werden sollen
# UND die später von nachgeschalteten Cmdlets (z.B. Stop-Process)
# benötigt werden:
Select-Object -Property Name, MainWindowTitle, Description, Company, Id

$buttonStop = $window.FindName('butStop')
$buttonCancel = $window.FindName('butCancel')
$code1 = { $window.DialogResult = $true }
$code2 = { $window.DialogResult = $false }

$buttonStop.add_Click($code1)
$buttonCancel.add_Click($code2)


# Fenster anzeigen
if ($window.ShowDialog())
{
  # Ergebnisse auswerten:
  $view.SelectedItems | Stop-Process -WhatIf
}
else
{
  Write-Warning 'Abbruch...'
}
