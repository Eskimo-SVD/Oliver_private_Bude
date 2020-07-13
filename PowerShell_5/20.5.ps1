for ($i = 1; $i -lt 10000; $i++)
{ 
    Start-Sleep -Seconds 1
    Write-Warning "Processing $i..."
}
