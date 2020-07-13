$code = {[Math]::Round(($this / 1MB),1) } 

Update-TypeData -MemberType ScriptMethod -MemberName ShowMB -Value $code -TypeName System.Int64 -Force

Update-TypeData -MemberType ScriptMethod -MemberName ShowMB -Value $code -TypeName System.Int32 -Force
