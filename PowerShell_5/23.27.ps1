$session = New-PSSession -ComputerName server02
Copy-Item -Path C:\daten\4302.jpg -Destination C:\ -ToSession $session
