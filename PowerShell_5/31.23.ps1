$xaml = @'
<Window xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  Title="PowerShell Cockpit"
  Width="300"
  MinWidth ="200"
  SizeToContent="Height"
  WindowStyle="ToolWindow">
    <Grid Margin="5">
      <Grid.ColumnDefinitions>
          <ColumnDefinition Width="50*"></ColumnDefinition>
          <ColumnDefinition Width="50*"></ColumnDefinition>
      </Grid.ColumnDefinitions>
      <Grid.RowDefinitions>
          <RowDefinition Height="Auto"></RowDefinition>
          <RowDefinition Height="Auto"></RowDefinition>
          <RowDefinition Height="*"></RowDefinition>
      </Grid.RowDefinitions>
  
      <Button Name="Aufgabe1" Width="80" Height="30" Margin="5" Grid.Column="0" Grid.Row="0">Aufgabe 1</Button>
      <Button Name="Aufgabe2" Width="80" Height="30" Margin="5" Grid.Column="1" Grid.Row="0">Aufgabe 2</Button>
      <Button Name="Aufgabe3" Width="80" Height="30" Margin="5" Grid.Column="0" Grid.Row="1">Aufgabe 3</Button>
      <Button Name="Aufgabe4" Width="80" Height="30" Margin="5" Grid.Column="1" Grid.Row="1">Aufgabe 4</Button>
      <Button Name="Aufgabe5" Width="80" Height="30" Margin="5" Grid.Column="0" Grid.Row="2">Aufgabe 5</Button>
      <Button Name="Aufgabe6" Width="80" Height="30" Margin="5" Grid.Column="1" Grid.Row="2">Aufgabe 6</Button>

    
    </Grid>
</Window>
'@

Add-Type -AssemblyName PresentationFramework
  
$reader = [System.XML.XMLReader]::Create([System.IO.StringReader]$XAML)
$window = [System.Windows.Markup.XAMLReader]::Load($reader)

# Aufgaben definieren
$code1 = { [Console]::Beep() }
$code2 = { Write-Host 'Du hast mich angeklickt!' }
$code3 = { Get-Service }
$code4 = { Get-Service | Out-Host }
$code5 = { Write-Warning 'Ich schlafe 5 Sekunden!'
           Start-Sleep -Seconds 5}
$code6 = { $antwort = [Windows.MessageBox]::Show('Wollen Sie das?', 'Mein Dialog', 'YesNo') }

# auf Schaltflächen zugreifen
$aufgabe1 = $window.FindName('Aufgabe1')
$aufgabe2 = $window.FindName('Aufgabe2')
$aufgabe3 = $window.FindName('Aufgabe3')
$aufgabe4 = $window.FindName('Aufgabe4')
$aufgabe5 = $window.FindName('Aufgabe5')
$aufgabe6 = $window.FindName('Aufgabe6')

# Code für das Click-Ereignis zuweisen
$aufgabe1.add_Click($code1)
$aufgabe2.add_Click($code2)
$aufgabe3.add_Click($code3)
$aufgabe4.add_Click($code4)
$aufgabe5.add_Click($code5)
$aufgabe6.add_Click($code6)

$null = $window.ShowDialog()
