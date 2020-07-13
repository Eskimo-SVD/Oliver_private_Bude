function Get-ChildItem_Ex
{
<#
.ForwardHelpTargetName Get-ChildItem
.ForwardHelpCategory Cmdlet
#>  [CmdletBinding(DefaultParameterSetName='Items', SupportsTransactions=$true,
    HelpUri='http://go.microsoft.com/fwlink/?LinkID=113308')]
    [OutputType('System.IO.FileInfo','System.IO.DirectoryInfo')]

  param
  (
    [Parameter(ParameterSetName='Items', Position=0, ValueFromPipeline=$true,
      ValueFromPipelineByPropertyName=$true)]
    [string[]]
    $Path,

    [Parameter(ParameterSetName='LiteralItems', Mandatory=$true, ValueFromPipelineByPropertyName=$true)]
    [Alias('PSPath')]
    [string[]]
    $LiteralPath,

    [Parameter(Position=1)]
    [string]
    $Filter,

    [string[]]
    $Include,

    [string[]]
    $Exclude,

    [Alias('s')]
    [switch]
    $Recurse,

    [switch]
    $Force,

    [switch]
    $Name,

    [datetime]
    $Before,

    [datetime]
    $After,

    [int64]
    $MaxFileSize,

    [int64]
    $MinFileSize,

    [int]
    $OlderThan,

    [int]
    $NewerThan,

    [string]
    $Sort
  )

  begin
  {
    try
    {
      # Initialize pre- and post-Pipeline command store:
      [string[]]$PrePipeline = ''
      [string[]]$PostPipeline = ''
      [string[]]$Pipeline = '& $wrappedCmd @PSBoundParameters'

      if ($PSBoundParameters.ContainsKey('Before'))
      {
        $PostPipeline += { Where-Object { $_.LastWriteTime -lt $Before } }
      }

      if ($PSBoundParameters.ContainsKey('After'))
      {
        $PostPipeline += { Where-Object { $_.LastWriteTime -gt $After } }
      }

      if ($PSBoundParameters.ContainsKey('MaxFileSize'))
      {
        $PostPipeline += { Where-Object { $_.LastWriteTime -le $MaxFileSize -and -not $_.PSIsContainer }}
      }

      if ($PSBoundParameters.ContainsKey('MinFileSize'))
      {
        $PostPipeline += { Where-Object { $_.Length -ge $MinFileSize -and -not $_.PSIsContainer}}
      }

      if ($PSBoundParameters.ContainsKey('OlderThan'))
      {
        $PostPipeline += {Where-Object {((Get-Date) - (New-TimeSpan -Days $OlderThan)) -gt $_.LastWriteTime}}
      }

      if ($PSBoundParameters.ContainsKey('NewerThan'))
      {
        $PostPipeline += {Where-Object {((Get-Date) - (New-TimeSpan -Days $NewerThan)) -lt $_.LastWriteTime}}
      }

      if ($PSBoundParameters.ContainsKey('Sort'))
      {
        $PostPipeline += { Sort-Object -Property $Sort }
      }

      # Remove additional parameters before forwarding them to the original cmdlet:
      $null = $PSBoundParameters.Remove('FileOnly')
      $null = $PSBoundParameters.Remove('FolderOnly')
      $null = $PSBoundParameters.Remove('Before')
      $null = $PSBoundParameters.Remove('After')
      $null = $PSBoundParameters.Remove('MaxFileSize')
      $null = $PSBoundParameters.Remove('MinFileSize')
      $null = $PSBoundParameters.Remove('OlderThan')
      $null = $PSBoundParameters.Remove('NewerThan')
      $null = $PSBoundParameters.Remove('Sort')

      $outBuffer = $null

      if ($PSBoundParameters.TryGetValue('OutBuffer', [ref]$outBuffer))
      {
        $PSBoundParameters['OutBuffer'] = 1
      }

      $wrappedCmd = $ExecutionContext.InvokeCommand.GetCommand('Get-ChildItem', 'Cmdlet')

      # add newly added pipeline components to the pipeline that gets executed:
      $scriptCmd = [scriptblock]::Create( (($PrePipeline + $Pipeline + $PostPipeline) |
        Where-Object { $_ }) -join ' | ')

      $steppablePipeline = $scriptCmd.GetSteppablePipeline($myInvocation.CommandOrigin)
      $steppablePipeline.Begin($PSCmdlet)
    } catch {
      throw
    }
  }

  process
  {
    try
    {
      $steppablePipeline.Process($_)
    } catch {
      throw
    }
  }

  end
  {
    try
    {
      $steppablePipeline.End()
    } catch {
      throw
    }
  }
}
