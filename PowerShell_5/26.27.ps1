mkdir c:\workflow | Out-Null

$options = New-PSWorkflowExecutionOption -OutOfProcessActivity ""
$options.MaxPersistenceStoreSizeGB = 3
$options.PersistencePath = 'c:\workflow'
Register-PSSessionConfiguration -Name Microsoft.PowerShell.CustomWorkflow -SessionType Workflow  -SessionTypeOption $options
