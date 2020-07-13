function Enable-WriteDebugBreakpoint
{
  [CmdletBinding(DefaultParameterSetName='Output')]
  param
  (
    [Parameter(ParameterSetName='Output')]
    [Switch]
    $VerboseOnly,

    [Parameter(ParameterSetName='Discard')]      
    [Switch]
    $Off
  )
    
  $results = Get-Ast -AstType Command |
  Where-Object { $_.CommandElements } |
  Where-Object { $_.CommandElements[0].Value -eq 'Write-Debug' } |
  ForEach-Object {
    # remove breakpoint on these lines if present
    $line = $_.Extent.StartLineNumber
    Get-PSBreakpoint -Script $psise.CurrentFile.FullPath | 
      Where-Object { $_.Line -eq $line } | 
      Remove-PSBreakpoint
      
    if ($PSCmdlet.ParameterSetName -ne 'Discard') { $_ } 
  } |
  Where-Object { !$VerboseOnly -or (@($_.CommandElements | 
  Where-Object { $_ -is [System.Management.Automation.Language.CommandParameterAst] -and $_.ParameterName -eq 'Verbose'}).Count -gt 0) } |
  ForEach-Object {
    $line = $_.Extent.StartLineNumber
    $argument = $_.CommandElements | Select-Object -Skip 1 | 
      Where-Object { $_ -is [System.Management.Automation.Language.StringConstantExpressionAst] } | 
      Select-Object -First 1 -ExpandProperty Value
    
    Get-PSBreakpoint -Script $psise.CurrentFile.FullPath | 
      Where-Object { $_.Line -eq $line } | 
      Remove-PSBreakpoint
      
    $null = Set-PSBreakpoint -Script $psise.CurrentFile.FullPath -Line $line -Action { Write-Host "Breaking at '$argument'" -ForegroundColor Yellow; break; }.GetNewClosure()
  }
}
