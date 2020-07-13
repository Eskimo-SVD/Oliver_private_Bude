$argumente = @{
    LogName = 'System'
    EntryType = 'Error', 'Warning'
    After = (Get-Date).AddDays(-1)
}

Get-EventLog @argumente
