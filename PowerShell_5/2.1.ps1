Import-Module BITSTransfer
$url = 'http://anon.nasa-global.edgesuite.net/HD_downloads/HD_Earth_Views.mov'
Start-BitsTransfer $url $HOME\video1.wmv
Invoke-Item $HOME\video1.wmv
