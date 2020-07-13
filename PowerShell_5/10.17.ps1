$path = "$env:temp\sample.log"

1..1000 | ForEach-Object {
  '{0:MMM dd, yyyy} Server_{1:d5} {2}' -f (Get-Date), (Get-Random -Maximum 99999), ('success', 'failure' | Get-Random)

} | Set-Content -Path $Path -Encoding UTF8

notepad $path
