#!/usr/bin/python3
from tkinter import *
import RPi.GPIO as gpio, signal

# Konstanten, GPIO-Initialisierung
# die Einstellung von WIRE muss verändert werden!
# (siehe ls -l /sys/devices/w1_bus_master1)
SWITCH=21
WIRE='/sys/devices/w1_bus_master1/10-000802ae1551/w1_slave'
gpio.setmode(gpio.BOARD)
gpio.setwarnings(False)  
gpio.setup(SWITCH, gpio.IN) 

# Reaktion auf Tastendruck an GPIO Pin 21
def taster(n):
  if n!=SWITCH: return
  if gpio.input(SWITCH) == gpio.LOW:
    lbl.configure(text='Der Taster ist gedrückt')
  else:
    lbl.configure(text='Der Taster ist nicht gedrückt')

# Tastenzustand alle 50ms auslesen
def polltaster():
  taster(SWITCH)
  mywin.after(50, polltaster)

# Temperatur auslesen und anzeigen
def temp():
  with open(WIRE) as f:
    f.readline()    # erste Zeile ignorieren
    s=f.readline()  # zweite Zeile
  n=s.find('t=')    # dort 't=' suchen
  if(n > 0):
    t = int(s[n+2:]) / 1000
  lbl2.configure(text='Temperatur: %.1f°C' % t)
  mywin.after(10000, temp)

# Programmende durch Windows-Close-Button
def win_close():
  mywin.quit()
  gpio.cleanup()
  sys.exit()

# Programmende durch Strg+C im Terminal
def strg_c(signal, frame):
  win_close()

# Benutzeroberfläche
mywin = Tk()
mywin.geometry("250x120")
mywin.wm_title('Input-Verarbeitung')
lbl = Label(mywin)
lbl.pack(pady=20)
polltaster()   # Tastenzustand ermitteln, lbl-Text einstellen
lbl2 = Label(mywin)
lbl2.pack(pady=20)
temp()         # Temperatur auslesen, lbl2-Text einstellen

# Ereignisse
gpio.add_event_detect(21, gpio.BOTH, bouncetime=50)
gpio.add_event_callback(21, taster)           # ^  50 ms Entprellzeit
mywin.protocol("WM_DELETE_WINDOW", win_close) # ordentliches Programmende, wenn Fenster geschlossen wird
signal.signal(signal.SIGINT, strg_c)          # auf Strg+C in Terminal reagieren
mywin.mainloop()