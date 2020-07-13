function Test-PipelineInput {
  [CmdletBinding(DefaultParameterSetName='Numerisch')]
  param (
    [Parameter(ValueFromPipeline=$true,ParameterSetName='Numerisch')]
    [double]
    $Zahl=-1,

    [Parameter(ValueFromPipeline=$true,ParameterSetName='Datum')]
    [datetime]
    $Datum = (Get-Date),

    [Parameter(ValueFromPipeline=$true,ParameterSetName='JaNein')]
    [bool]
    $Boolean = $false,

    [Parameter(ValueFromPipeline=$true,ParameterSetName='Text')]
    [string]
    $Text = ''
  )

  process {
    switch ($PSCmdlet.ParameterSetName)
    {
        'Numerisch'   { "Es wurde die Zahl $Zahl �bergeben" }
        'Datum'       { "Es wurde das Datum $Datum �bergeben" }
        'JaNein'      { "Es wurde der boolsche Wert $Boolean �bergeben" }
        'Text'        { "Es wurde der Text $Text �bergeben" }
    }
  }
}
