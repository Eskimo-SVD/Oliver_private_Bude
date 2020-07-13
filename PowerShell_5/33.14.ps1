function Get-TokenSimple
{

  [CmdletBinding(DefaultParameterSetName='All')]
  param
  (
    [Parameter(Mandatory=$false, Position=0, ParameterSetName='Selected')]
    [System.Management.Automation.PSTokenType]
    $Kind = 'Variable',
    
    [String]
    $Code = $psise.CurrentFile.Editor.Text
  )    
    
  # provide buckets for errors and tokens
  $Errors = $null
    
  # parse the code
  $Tokens = [System.Management.Automation.PSParser]::Tokenize($Code, [ref]$Errors)
  if ($PSCmdlet.ParameterSetName -eq 'All')
  {
    $Tokens
  } 
  else
  {
    $Tokens | Where-Object { $_.Type -eq $Kind }
  }
}
