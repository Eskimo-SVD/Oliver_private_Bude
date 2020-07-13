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
