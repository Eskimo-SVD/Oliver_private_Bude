function New-ProxyFunction
{
  param
  (
    [Parameter(Mandatory=$true)]
    $CmdletName
  )

  $cmd = Get-Command $CmdletName -CommandType Cmdlet
  $meta = New-Object System.Management.Automation.CommandMetadata($cmd)
  $logic = [System.Management.Automation.ProxyCommand]::Create($meta)

  $FunctionName = '{0}_Ex' -f $CmdletName

  $code = "
function $FunctionName
{
$logic
}"

  $NewFile = $psISE.CurrentPowerShellTab.files.Add()
  $NewFile.Editor.Text = $code
}
