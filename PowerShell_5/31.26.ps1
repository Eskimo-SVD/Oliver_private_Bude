function Start-InNewThread
{
  param
  (
    [ScriptBlock]$Code,
    
    [Hashtable]$Parameters = @{}
  )
  
  $powershell = [PowerShell]::Create()
  $action = {
   
    $status = $event.SourceEventArgs.InvocationStateInfo.State
    
    if ($status -eq 'Completed')
    {
      try
      {
        $powershell = $event.Sender
        $powershell.Runspace.Close()
        $powershell.Dispose()
        Unregister-Event -SourceIdentifier $event.SourceIdentifier 
      }
      catch
      {
        Write-Warning "$_"
      }
    }
  }
  
  $null = Register-ObjectEvent -InputObject $powershell -Action $action -EventName InvocationStateChanged 
  $null = $powershell.AddScript($Code)
  
  foreach($key in $Parameters.Keys)
  {
    $null = $powershell.AddParameter($key, $Parameters.$key)
  }
 
  $handle = $powershell.BeginInvoke()
}


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
$code1 = { [Console]::Beep(1000,1000) }
$code2 = { param($UI)
           $UI.WriteLine('Du hast mich angeklickt!') }
$code3 = { Get-Service }
$code4 = { param($UI)
           $UI.WriteLine((Get-Service | Out-String)) }
$code5 = { param($UI)
           $UI.WriteWarningLine('Ich schlafe 5 Sekunden!')
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
$aufgabe1.add_Click({ Start-InNewThread -Code $code1 })
$aufgabe2.add_Click({ Start-InNewThread -Code $code2 -Parameter @{UI=$Host.UI} })
$aufgabe3.add_Click({ Start-InNewThread -Code $code3 })
$aufgabe4.add_Click({ Start-InNewThread -Code $code4 -Parameter @{UI=$Host.UI} })
$aufgabe5.add_Click({ Start-InNewThread -Code $code5 -Parameter @{UI=$Host.UI} })
$aufgabe6.add_Click({ Start-InNewThread -Code $code6 })

$null = $window.ShowDialog()
