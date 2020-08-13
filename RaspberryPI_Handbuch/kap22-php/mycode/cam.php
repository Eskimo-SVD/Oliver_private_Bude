<?php

$FVI = FILTER_VALIDATE_INT;
$width      = filter_input(INPUT_POST, 'width',      $FVI);
$height     = filter_input(INPUT_POST, 'height',     $FVI);
$contrast   = filter_input(INPUT_POST, 'contrast',   $FVI);
$brightness = filter_input(INPUT_POST, 'brightness', $FVI);

// sinnvolle Defaultwerte sicherstellen
if(!$width || $width<100 || $width>2592)
  $width = 640;
if(!$height || $height<100 || $height>1944)
  $height = 480;
if(!$contrast || $contrast<100 || $contrast>100)
  $contrast = 0;
if(!$brightness || $brightness<0 || $brightness>100)
  $brightness = 50;

$opts = "-w $width -h $height -co $contrast -br $brightness ";
$imgdata = shell_exec("/usr/bin/raspistill $opts -n -t 1 -o -");
header('Content-type: image/jpeg');
header('Content-length: ' . strlen($imgdata));
echo $imgdata;
  
?>
  