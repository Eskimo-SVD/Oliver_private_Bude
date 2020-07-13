{
  param
  (
    [Parameter(ValueFromPipeline=$true, ValueFromPipelineByPropertyName = $true)]
    [Alias('Path','FullName')]
    [String]
    $FilePath
  )
  process
  {
    "bearbeite Pfad $FilePath"
  }
}