Add-Type -AssemblyName PresentationFramework

$window = New-Object Windows.Window
$window.Title='Send Message'
$window.SizeToContent='WidthAndHeight'
$window.WindowStyle='ToolWindow'
$window.ResizeMode='NoResize'

$stackpanel1 = New-Object -TypeName Windows.Controls.StackPanel
$stackpanel1.Orientation = 'Vertical'
$stackpanel1.Margin = 10

$window.Content = $stackpanel1

$stackpanel2 = New-Object -TypeName Windows.Controls.StackPanel
$stackpanel2.Orientation = 'Horizontal'
$stackpanel2.Margin = 5

$stackpanel3 = New-Object -TypeName Windows.Controls.StackPanel
$stackpanel3.Orientation = 'Horizontal'
$stackpanel3.Margin = 5

$stackpanel4 = New-Object -TypeName Windows.Controls.StackPanel
$stackpanel4.Orientation = 'Horizontal'
$stackpanel4.Margin = 5
$stackpanel4.HorizontalAlignment = 'Right'

$null = $stackpanel1.Children.Add($stackpanel2)
$null = $stackpanel1.Children.Add($stackpanel3)
$null = $stackpanel1.Children.Add($stackpanel4)

$label1 = New-Object -TypeName Windows.Controls.Label
$label1.Width = 100
$label1.Content = 'Name'

$textBox1 = New-Object -TypeName Windows.Controls.TextBox
$textBox1.Width = 300
$textBox1.Name = 'txtName'

$null = $stackpanel2.Children.Add($label1)
$null = $stackpanel2.Children.Add($textBox1)

$label2 = New-Object -TypeName Windows.Controls.Label
$label2.Width = 100
$label2.Content = 'Email'

$textBox2 = New-Object -TypeName Windows.Controls.TextBox
$textBox2.Width = 300
$textBox2.Name = 'txtEmail'

$null = $stackpanel3.Children.Add($label2)
$null = $stackpanel3.Children.Add($textBox2)

$button1 = New-Object -TypeName Windows.Controls.Button
$button1.Width = 80
$button1.Content = 'Send'
$button1.Margin = 5

$button2 = New-Object -TypeName Windows.Controls.Button
$button2.Width = 80
$button2.Content = 'Cancel'
$button2.Margin = 5

$null = $stackpanel4.Children.Add($button1)
$null = $stackpanel4.Children.Add($button2)

$label = New-Object Windows.Controls.Label

$window.ShowDialog()
