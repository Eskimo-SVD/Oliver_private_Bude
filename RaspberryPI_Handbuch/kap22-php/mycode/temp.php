<!DOCTYPE html>
<meta charset="utf-8">
<?php

try {
  $id = '10-000802ae1551';
  $fname = "/sys/devices/w1_bus_master1/$id/w1_slave";
  $data = file_get_contents($fname);
  $pos= strpos($data, 't=');
  $temp = intval(substr($data, $pos+2)) / 1000;
  echo "<p>Die Temperatur beträgt $temp Grad Celsius.";
} catch(Exception $e) {
  echo "<p>Es ist ein Fehler aufgetreten.";
}
  
?>
  