$driveC = Get-WmiObject -Class Win32_LogicalDisk -Filter 'DeviceID="C:"'
$sizeByte = $driveC.Size
$sizeGB = $sizeByte / 1GB

'Festplatte C:\ Gr��e: {0:n1} GB' -f $sizeGB
