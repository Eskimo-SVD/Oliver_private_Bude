$excel = New-Object -ComObject Excel.Application
$workbook = $excel.Workbooks.Add()
$excel.Visible = $true
$excel.Cells.Item(1,1) = "Service Name" 
$excel.Cells.Item(1,2) = "Service Status"
$excel.Cells.Item(1,3) = "Service Status"

$i = 2 
Get-Service | 
  ForEach-Object { 
    $excel.Cells.Item($i,1) = $_.name
    $excel.Cells.Item($i,2) = $_.status
    $excel.Cells.Item($i,3) = "$($_.status)"
    $i=$i+1
  }
