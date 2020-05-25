:: Programmname: check.bat
:: keine Anzeige der Eingabe (auch nicht des echo's)
@echo off

:: Programm starten
exit_code.exe

:: Errorlevel auswerten
if errorlevel 1 goto eins
if errorlevel 0 goto null

:: Errorlevel 1
:eins
   echo Fehler: Ende-Status ist 1
   goto ende
:null
   echo Alles Ok: Ende-Status ist 0
   goto ende
:ende
   PAUSE
