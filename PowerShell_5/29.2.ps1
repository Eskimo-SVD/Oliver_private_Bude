$size = 21367125376521 | Add-Member -MemberType ScriptMethod -Name ShowMB -Value { [Math]::Round(($this / 1MB),1) } -PassThru
