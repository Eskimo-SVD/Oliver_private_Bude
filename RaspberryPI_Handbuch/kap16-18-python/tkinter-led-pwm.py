#!/usr/bin/python3
from tkinter import *
import RPi.GPIO as gpio, signal
gpio.setmode(gpio.BOARD)
gpio.setwarnings(False)  
gpio.setup(26, gpio.OUT) 
pwm = gpio.PWM(26, 1000)    # Frequenz: 1000 Hertz
pwm.start(50)               # Duty: anfangs 50%

# Reaktion auf Mausklick im Fenster
def pwm_change(value):
  pwm.ChangeDutyCycle(float(value))
  
# Programmende durch Windows-Close-Button
def win_close():
  gpio.cleanup()
  mywin.quit()

# Programmende durch Strg+C im Terminal
def strg_c(signal, frame):
  win_close()

# regelmäßiger Aufruf, damit Strg+C funktioniert
def do_nothing():
  mywin.after(200, do_nothing)

# Benutzeroberfläche
mywin = Tk()
mywin.wm_title('LED-Helligkeit')
lbl = Label(mywin, text='LED-Helligkeit mit PWM steuern')
ledscale = Scale(mywin, from_=0, to=100, orient=HORIZONTAL, command=pwm_change)
ledscale.set(50)
lbl.grid(column=0, row=0, padx=5, pady=5)
ledscale.grid(column=0, row=1, padx=5, pady=5)

# Ereignisse
mywin.protocol("WM_DELETE_WINDOW", win_close) # ordentliches Programmende, wenn Fenster geschlossen wird
signal.signal(signal.SIGINT, strg_c) # auf Strg+C in Terminal reagieren
mywin.after(200, do_nothing)         # damit Strg+C funktioniert
mywin.mainloop()

