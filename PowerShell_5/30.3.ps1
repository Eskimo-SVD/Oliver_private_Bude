function Out-LogFile
{
    param
    (
        [Parameter(Mandatory=$true)]
        $Path,

        [Parameter(ValueFromPipeline=$true)]
        $InputObject
    )

    process
    {
        $InputObject | Out-File -FilePath $Path -Append
        $InputObject
    }
}
