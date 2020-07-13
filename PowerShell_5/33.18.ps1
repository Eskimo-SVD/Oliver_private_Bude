function Test-Script
{
  param
  (
    [Parameter(Mandatory=$true, ValueFromPipeline=$true,
     ValueFromPipelineByPropertyName=$true)]
    [String]
    [Alias('FullName')]
    $Path
  )
  
  process
  {
    $Errors = $null
    $exists = Test-Path -Path $Path
    if ($exists)
    {
      $text = Get-Content -Path $Path -Raw
      if ($text -eq $null) { $text = '' }
      $null = [System.Management.Automation.PSParser]::Tokenize($text, [ref]$Errors)
      $Message = ''
      if ($Errors.Count -gt 0)
      {
        $Message = $errors[0].Message
      }
      $result = [Ordered]@{
        Path = $Path
        Error = $Errors.Count -gt 0
        Message = $Message
        Errors = $Errors
      }

      New-Object -TypeName PSObject -Property $result   
    }
  }
}
