$Code = 
{
  param
  (
    $LogName = 'System'
  )
  
  Get-EventLog -LogName $LogName -EntryType Error -Newest 5
}

Invoke-Command -ScriptBlock $Code -ComputerName Server_012_win -ArgumentList Application
