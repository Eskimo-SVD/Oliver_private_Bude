$xaml = @'
<Window xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  Title="Send Message"
  Width="300"
  MinWidth ="200"
  SizeToContent="Height"
  WindowStyle="ToolWindow">
    <Grid Margin="5">
        <Grid.ColumnDefinitions>
            <ColumnDefinition Width="Auto"></ColumnDefinition>
            <ColumnDefinition Width="*"></ColumnDefinition>
        </Grid.ColumnDefinitions>
        <Grid.RowDefinitions>
            <RowDefinition Height="Auto"></RowDefinition>
            <RowDefinition Height="Auto"></RowDefinition>
            <RowDefinition Height="*"></RowDefinition>
        </Grid.RowDefinitions>
  
      <Label Grid.Column="0">Name</Label>
      <TextBox Grid.Column="1"  Name="txtName" Margin="5"></TextBox>
    
      <Label Grid.Column="0" Grid.Row="1">Email</Label>
      <TextBox  Grid.Column="1" Grid.Row="1" Name="txtEmail" Margin="5"></TextBox>
    
    <StackPanel Grid.ColumnSpan="2" Grid.Row="2" Orientation="Horizontal" HorizontalAlignment="Right" VerticalAlignment="Bottom">
      <Button Name="butSend" Width="80" Height="30" Margin="5">Send</Button>
      <Button Name="butCancel" Width="80" Height="30" Margin="5">Cancel</Button>
    </StackPanel>
    </Grid>
</Window>
'@

Add-Type -AssemblyName PresentationFramework

$reader = [System.XML.XMLReader]::Create([System.IO.StringReader]$XAML)
$window = [System.Windows.Markup.XAMLReader]::Load($reader)

# Elemente ansprechen, mit denen etwas passieren soll:
$textBox1 = $window.FindName('txtName')
$textBox2 = $window.FindName('txtEmail')
$buttonSend = $window.FindName('butSend')
$buttonCancel = $window.FindName('butCancel')

# Eingabecursor in erstes Textfeld setzen:
$null = $textBox1.Focus()

# Click-Ereignisse der Schaltflächen mit Aktion versehen:
$code1 = { $window.DialogResult = $true }
$code2 = { $window.DialogResult = $false }

$buttonSend.add_Click($code1)
$buttonCancel.add_Click($code2)

# KeyPress-Ereignisse der TextBox-Elemente definieren
$code3 = {
  [System.Windows.Input.KeyEventArgs]$e = $args[1]
  if ($e.Key -eq 'ENTER') { $textBox2.Focus() }  
}

$code4 = {
  [System.Windows.Input.KeyEventArgs]$e = $args[1]
  if ($e.Key -eq 'ENTER') { $window.DialogResult = $true }  
}
  
$textBox1.add_KeyUp($code3)
$textBox2.add_KeyUp($code4)

$DialogResult = $window.ShowDialog()
if ($DialogResult -eq $true)
{
  $info = [Ordered]@{
    Name = $textBox1.Text
    Email = $textBox2.Text
  }
  New-Object -TypeName PSObject -Property $info
}
else
{
  Write-Warning 'Abbruch durch den User.'
}
