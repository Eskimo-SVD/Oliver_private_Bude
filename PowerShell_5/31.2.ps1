$xaml = @'
<Window xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
  Title="Send Message"
  SizeToContent="WidthAndHeight"
  WindowStyle="ToolWindow"
  ResizeMode="NoResize">

  <StackPanel Orientation="Vertical" Margin="10">

    <StackPanel Orientation="Horizontal" Margin="5">
      <Label Width="100">Name</Label>
      <TextBox  Name="txtName" Width="300"></TextBox>
    </StackPanel>

    <StackPanel Orientation="Horizontal" Margin="5">
      <Label Width="100">Email</Label>
      <TextBox  Name="txtEmail" Width="300"></TextBox>
    </StackPanel>

    <StackPanel Orientation="Horizontal" HorizontalAlignment="Right">
      <Button Name="butSend" Width="80" Margin="5">Send</Button>
      <Button Name="butCancel" Width="80" Margin="5">Cancel</Button>
    </StackPanel>
  
  </StackPanel>
</Window>
'@

Add-Type -AssemblyName PresentationFramework

$reader = [System.XML.XMLReader]::Create([System.IO.StringReader]$XAML)
$window = [System.Windows.Markup.XAMLReader]::Load($reader)

$window.ShowDialog()
