function Get-TokenDetailed
{

  [CmdletBinding(DefaultParameterSetName='All')]
  param
  (
    [Parameter(Mandatory=$false, Position=0, ParameterSetName='Kind')]
    [System.Management.Automation.Language.TokenKind]
    $Kind = 'Variable',

    [Parameter(Mandatory=$false, Position=0, ParameterSetName='Flag')]      
    [System.Management.Automation.Language.TokenFlags]
    $Flag = 'CommandName',
    
    $Code = $psise.CurrentFile.Editor.Text
  )
    
  # provide buckets for errors and tokens
  $Errors = $Tokens = $null
    
  # parse the code
  $null = [System.Management.Automation.Language.Parser]::ParseInput($Code, [ref]$Tokens, [ref]$Errors)
    
  if ($PSCmdlet.ParameterSetName -eq 'All')
  {
    $Tokens
  } 
  elseif ($PSCmdlet.ParameterSetName -eq 'Flag')
  {
    $Tokens | Where-Object { $_.TokenFlags -eq $Flag }   
  }
  else
  {
    $Tokens | Where-Object { $_.Kind -eq $Kind }
  }
}
