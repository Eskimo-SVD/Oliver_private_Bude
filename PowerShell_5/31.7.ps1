$xaml = @'
<Window xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
  Title="Aktion auswählen"
  SizeToContent="WidthAndHeight"
  WindowStyle="ToolWindow"
  ResizeMode="NoResize">

    <StackPanel Orientation="Vertical" Margin="10">

        <StackPanel Orientation="Vertical" Margin="5">
            <RadioButton x:Name="radioButton1" Content="Neustart" Margin="5" IsChecked="True"/>
            <RadioButton x:Name="radioButton2" Content="Herunterfahren" Margin="5"/>
            <RadioButton x:Name="radioButton3" Content="Abmelden" Margin="5"/>
        </StackPanel>

        
        <StackPanel Orientation="Horizontal" HorizontalAlignment="Right">
            <Button x:Name="butSend" Width="80" Margin="5" Content="OK"/>
            <Button x:Name="butCancel" Width="80" Margin="5" Content="Cancel"/>
        </StackPanel>

    </StackPanel>
</Window>
'@

Add-Type -AssemblyName PresentationFramework

$reader = [System.XML.XMLReader]::Create([System.IO.StringReader]$XAML)
$window = [System.Windows.Markup.XAMLReader]::Load($reader)

# Elemente ansprechen, mit denen etwas passieren soll:
$buttonSend = $window.FindName('butSend')
$buttonCancel = $window.FindName('butCancel')

$radio1 = $window.FindName('radioButton1')
$radio2 = $window.FindName('radioButton2')
$radio3 = $window.FindName('radioButton3')

# Click-Ereignisse der Schaltflächen mit Aktion versehen:
$code1 = { $window.DialogResult = $true }
$code2 = { $window.DialogResult = $false }

$buttonSend.add_Click($code1)
$buttonCancel.add_Click($code2)

$DialogResult = $window.ShowDialog()
if ($DialogResult -eq $true)
{
  if ($radio1.isChecked)
  {
    1
  }
  elseif ($radio2.isChecked)
  {
    2
  }
  elseif ($radio3.isChecked)
  {
    3
  }
}
else
{
  Write-Warning 'Abbruch durch den User.'
}
