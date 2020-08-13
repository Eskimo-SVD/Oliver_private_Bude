<html>
<!-- Datei /var/www/index.php -->
<head>
  <meta http-equiv="refresh" content="60;url=/index.php">
  <title>PumPi</title>
</head>
<body>
```

```php
<?php

if ( $_GET['schwelle'] <> "" )
{
  $handle = fopen("schwelle.txt", "w");
  fwrite($handle, $_GET['schwelle']);
  fclose($handle);
  echo "Auswahl gespeichert, Aktivierung innerhalb von 5 Minuten.";
}

?>
```

```html
<font face="arial,helvetica">
<table border=0>
<tr>
  <td align=right valign=top>
    WLAN-Signal: <br>
    Verbindung zur Steckdose: <br>
    Verbindung zur Webbox: <br>
    PV-Leistung aktuell: <br>
  </td>
  <td align=left valign=top>
    <? include("wlansig.txt") ?><br>
    <? include("netioconn.txt") ?><br>
    <? include("webboxconn.txt") ?><br>
    <? include("pvleistung.txt") ?><br>
    <br>
  </td>
</tr>
<tr>
  <td valign=top>
    <br>
    <form action="index.php" method="get">
    <p>Schaltschwelle</br>
  <td align=left valign=top>
    <? include("wlansig.txt") ?><br>
    <? include("netioconn.txt") ?><br>
    <? include("webboxconn.txt") ?><br>
    <? include("pvleistung.txt") ?><br>
    <br>
  </td>
</tr>
<tr>
  <td valign=top>
    <br>
    <form action="index.php" method="get">
    <p>Schaltschwelle</br>
    (aktuell: <? include("schwelle.txt"); ?>)
    <br>
    <br>
    <input type=radio name="schwelle" value="1">
      1 (permanent an)<br>
    <input type=radio name="schwelle" value="0">
      0 (permanent aus)<br><br>
    <input type=radio name="schwelle" value="1000">1000 Watt<br>
    <input type=radio name="schwelle" value="2000">2000 Watt<br>
    <input type=radio name="schwelle" value="3000">3000 Watt<br>
    <input type=radio name="schwelle" value="4000">4000 Watt<br>
    <input type=radio name="schwelle" value="5000">5000 Watt<br>
    <input type=radio name="schwelle" value="6000">6000 Watt<br>
    <input type=radio name="schwelle" value="7000">7000 Watt<br>
    <br>
    <input type=submit value="Aktivieren"><br>
    </p>
  </td>
  <td align=left valign=top>
    <br>
    <img src="webbox-4h.gif"><br>
    <img src="webbox-24h.gif"><br>
  </td>    
</tr>
</table>
<font size="1">
<br>
<? passthru("uptime"); ?>
</body>
</html>
