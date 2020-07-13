Add-Type -AssemblyName PresentationFramework

$xaml = @"
<Window
 xmlns='http://schemas.microsoft.com/winfx/2006/xaml/presentation'
 SizeToContent='WidthAndHeight'
 WindowStartupLocation = 'CenterScreen'
 ResizeMode = 'NoResize'
 WindowStyle = 'None'
 Topmost='True' >

  <Label FontSize="100" FontFamily='Stencil' Background='Red' Foreground='White' BorderThickness='2' BorderBrush='Yellow'>
    Feueralarm!
  </Label>
</Window>
"@

$reader = [System.XML.XMLReader]::Create([System.IO.StringReader] $xaml)
$window = [System.Windows.Markup.XAMLReader]::Load($reader)

$null = $window.Show()
Start-Sleep -Seconds 5
$window.Close()
