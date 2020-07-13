$e = Get-ChildItem -Path $env:windir -Recurse -ErrorAction SilentlyContinue | 
  Select-Object -First 5
$e
