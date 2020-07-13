function Lock-Screen
{
  param
  (
    $Title = 'Access temporarily unavailable',
    $Delay = 10
  )
  
  Add-Type -AssemblyName PresentationFramework
  
  $window = New-Object Windows.Window
  $label = New-Object Windows.Controls.Label
  $label.Content = $Title
  $label.FontSize = 60
  $label.FontFamily = 'Tahoma'
  $label.Background = 'Transparent'
  $label.Foreground = 'Red'
  $label.HorizontalAlignment = 'Center'
  $label.VerticalAlignment = 'Center'
  $Window.AllowsTransparency = $True
  $Window.Opacity = 0.6
  $window.WindowStyle = 'None'
  $window.Content = $label
  $window.Left = $window.Top = 0
  $window.WindowState = 'Maximized'
  $window.Topmost = $true
  $null = $window.Show()
  Start-Sleep -Seconds $Delay
  $window.Close()
}

Lock-Screen -Title 'Zugang vorübergehend verboten!' -Delay 4
