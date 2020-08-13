<html>
<!-- Datei /var/www/fernbedienung.php -->
<head>
</head>
<body>
<h1 align="center">Funk-Fernbedienung</h1>
<?php 
if(isset($_GET['command'])) {
  if($_GET['command'] === 'sd-an') {
    $val = trim(@shell_exec(
      "/home/pi/rcswitch-pi/send 11000 3 1"));
  }
  elseif($_GET['command'] === 'sd-aus') {
    $val = trim(@shell_exec(
      "/home/pi/rcswitch-pi/send 11000 3 0"));
  }
}
?>

<div align="center">			
<a href="<?php print($_SERVER['PHP_SELF']); ?>?command=sd-an">
Steckdose an</a>
<br>
<br>
<a href="<?php print($_SERVER['PHP_SELF']); ?>?command=sd-aus">
Steckdose aus</a>
</div>

</body>
</html>