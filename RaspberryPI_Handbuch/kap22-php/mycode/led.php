<!DOCTYPE html>
<meta charset="utf-8">
<?php

// Pin 26 als Output verwenden
exec('gpio -1 mode 26 out');

// POST-Formulardaten verarbeiten
if(isset($_POST['newstate'])) {
  $new = $_POST['newstate'];
  if($new=='0' || $new=='1')
    exec("gpio -1 write 26 $new");
}

// aktuellen Zustand und Button zum Umschalten anzeigen
$current = exec('gpio -1 read 26');
if($current == '0') {
  echo "<p>Die LED ist momentan ausgeschaltet.";
  echo "<p><form action='led.php' method='post'>
           <input type='hidden' name='newstate' value='1'>
           <input type='submit' value='LED einschalten'>      
           </form>";  
  }
else {
  echo "<p>Die LED ist momentan eingeschalten.";
  echo "<p><form action='led.php' method='post'>
           <input type='hidden' name='newstate' value='0'>
           <input type='submit' value='LED ausschalten'>      
           </form>";  
  }
  
?>
  