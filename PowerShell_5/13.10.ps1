$scriptblock = 
{
    Write-Host 'Write Host'
    Write-Verbose 'Write-Verbose'
    Write-Warning 'Write-Warning'
    Write-Debug 'Write-Debug'
    Write-Information 'Write-Information'
    Write-Output 'Write-Output'
    1..10 | 
      ForEach-Object { 
        Write-Progress -Activity 'Write-Progress' -Status $_ -PercentComplete ($_*10)
        Start-Sleep -Milliseconds 300
      }
}

$ergebnis = & $scriptblock
"Ergebnis geliefert: $ergebnis"
