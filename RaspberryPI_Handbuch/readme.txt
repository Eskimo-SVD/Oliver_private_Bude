Das sind Beispieldateien zum Buch

  Raspberry Pi -- Das umfassende Handbuch, 6. Auflage
  Rheinwerk Verlag 2019
  (c) Michael Kofler, Christoph Scherbeck, Charly Kühnast, Rheinwerk Verlag

  https://pi-buch.info

Die Nutzung des Codes in eigenen Projekten ist uneingeschränkt erlaubt.

Die Weitergabe der gesammelten Beispieldateien ist nicht zulässig. Die
Beispieldateien sind integraler Bestandteil des Buchs.

Keinerlei Garantie für Fehler, Hardware-Schäden etc!

---

Die Beispieldateien sind kapitelweise in TAR- oder ZIP-Archiven organisiert.

Kopieren Sie zuerst die betreffende *.tgz- oder *.zip-Datei auf 
Ihren Raspberry Pi, am einfachsten mit scp (siehe Abschnitt 5.3).

Den Inhalt von TAR-Dateien sehen Sie sich mit tar tzf an:

  tar tzf kapnn-xxx.tgz

Zum Auspacken erzeugen Sie im Terminal mit mkdir ein Verzeichnis und
verwenden dann das Kommando tar xzf (siehe Abschnitt 3.7). Z.B.:

  mkdir smartmeter
  cd smartmeter
  tar xzf ../kap29-stromzaehler.tgz

Bei ZIP-Dateien verwenden Sie zipinfo und unzip:

  zipinfo kap11-led-mot-rel.zip
  unzip kap11-led-mot-rel.zip
