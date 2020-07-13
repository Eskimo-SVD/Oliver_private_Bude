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
