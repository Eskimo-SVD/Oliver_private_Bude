$ie = New-Object -COMObject InternetExplorer.Application 
$ie.Navigate2('www.powertheshell.com')
$ie.Visible = $true
