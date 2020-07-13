$xaml = @'
<Window xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  Title="Dienst stoppen"
  SizeToContent="WidthAndHeight"
  WindowStyle="ToolWindow"
  ResizeMode="NoResize">

    <StackPanel Orientation="Vertical" Margin="10">

        <StackPanel Orientation="Vertical" Margin="5">
            <ComboBox Name="combo1" DisplayMemberPath="DisplayName" Width="300"/>
        </StackPanel>

        
        <StackPanel Orientation="Horizontal" HorizontalAlignment="Right">
            <Button x:Name="butStop" Width="80" Margin="5" Content="Stop"/>
            <Button x:Name="butCancel" Width="80" Margin="5" Content="Done"/>
        </StackPanel>

    </StackPanel>
</Window>
'@

Add-Type -AssemblyName PresentationFramework

$reader = [System.XML.XMLReader]::Create([System.IO.StringReader]$XAML)
$window = [System.Windows.Markup.XAMLReader]::Load($reader)

# Elemente ansprechen, mit denen etwas passieren soll:
$buttonStop = $window.FindName('butStop')
$buttonCancel = $window.FindName('butCancel')
$comboBox1 = $window.FindName('combo1')

# Click-Ereignisse der Schaltflächen mit Aktion versehen:
$code1 = { 
  $comboBox1.SelectedItem | Stop-Service -WhatIf
  RefreshComboBox
}
$code2 = { $window.Close() }

$buttonStop.add_Click($code1)
$buttonCancel.add_Click($code2)

# Dienste-Liste füllen
function RefreshComboBox
{
  $liste = Get-Service | Where-Object Status -eq Running
  $comboBox1.ItemsSource = $liste
  $comboBox1.SelectedIndex = 1
}
RefreshComboBox
$null = $window.ShowDialog()
