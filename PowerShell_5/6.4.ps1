$infos = systeminfo.exe /FO CSV | Select-Object -Skip 1
$einzelinfos = $infos -split '","'
$betriebssystem, $architektur = $einzelinfos[1,13]
"Sie betreiben $betriebssystem auf $architektur"
