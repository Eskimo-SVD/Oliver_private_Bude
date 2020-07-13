@'
<?xml version="1.0" ?>
<Belegschaft Zweigstelle="Hannover" Typ="Aussendienst">
  <Mitarbeiter>
    <Name>Tobias Weltner</Name>
    <Rolle>Leitung</Rolle>
    <Alter>47</Alter>
  </Mitarbeiter>
  <Mitarbeiter>
    <Name>Cofi Heidecke</Name>
    <Rolle>Sicherheit</Rolle>
    <Alter>23</Alter>
  </Mitarbeiter>
</Belegschaft>
'@ | Set-Content -Path $env:temp\mitarbeiter.xml -Encoding UTF8
