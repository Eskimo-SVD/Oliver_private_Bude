Get-ChildItem -Path $HOME -File -Recurse -Force -ErrorAction Ignore | ForEach-Object -Begin { $i=0 } -Process { $i+=$_.Length } -End { [Math]::Round( ($i/1MB), 1) }
