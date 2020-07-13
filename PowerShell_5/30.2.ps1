function Out-LogFile
{
    param
    (
        [Parameter(Mandatory=$true)]
        $Path,

        [Parameter(ValueFromPipeline=$true)]
        $InputObject
    )

    end
    {
        $data = @($Input)
        $data | Out-File -FilePath $Path -Append
        $data
    }
}
