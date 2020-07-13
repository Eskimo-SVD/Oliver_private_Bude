function Out-LogFile
{
    param
    (
        [Parameter(Mandatory=$true)]
        $Path,

        [Parameter(ValueFromPipeline=$true)]
        $InputObject
    )

    begin
    {
        # Zugriff auf das Cmdlet, an das die Daten geliefert werden sollen:
        $Cmdlet = 'Out-File'
        $wrappedCmd = $ExecutionContext.InvokeCommand.GetCommand($cmdlet, 'Cmdlet')

        # Befehlszeile festlegen. $wrappedCmd steht für das Cmdlet "Out-File":
        $scriptCmd = {&  $wrappedCmd -FilePath $Path -Append }

        # Zugriff auf diesen Befehl erhalten:
        $steppablePipeline = $scriptCmd.GetSteppablePipeline($myInvocation.CommandOrigin)

        # begin-Block von "Out-File" aufrufen:
        $steppablePipeline.Begin($PSCmdlet)
}

    process
    {
        # process-Bock von "Out-File" aufrufen:
        $steppablePipeline.Process($_)

        # HIER DIE ERWEITERUNG:
        # AUSSERDEM das einlaufende Element in die Konsole zurückgeben:
        $_
    }

    end
    {
        # end-Block von "Out-File" aufrufen:
        $steppablePipeline.End()
    }
}
