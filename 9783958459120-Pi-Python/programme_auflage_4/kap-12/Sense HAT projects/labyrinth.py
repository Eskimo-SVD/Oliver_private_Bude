#! /usr/bin/python3
#----------------------------------------------------------------
# Dateiname: labyrinth.py
# Der RPi trägt einen SenseHat.
# Durch Kippen des RPi kann eine "Murmel" bewegt werden.
#  
# Michael Weigend
# Raspberry Pi programmieren mit Python, 4. Auflage, mitp 2019
# Kap. 12
# Michael Weigend 20. November 2018
#----------------------------------------------------------------

import sense_hat, time


PIXEL = [50, 0, 200]
X = [200, 200, 200]
_ = [0, 0, 0]

LABYRINTH = [X, X, X, X, X, X, X, X,
             X, _, _, _, _, X, _, X,
             X, X, X, X, _, X, _, X,
             X, _, _, _, _, X, _, X,
             X, _, X, X, X, X, _, X,
             X, _, X, _, _, _, _, X,
             X, _, _, _, X, X, _, X,
             X, X, X, X, X, X, X, X]

ZEIT = 0.2

def refresh():
    global x, y
    if sh.get_pixel(x_neu, y_neu) != X:
       sh.set_pixel(x,  y , _)
       x, y, = x_neu, y_neu
       sh.set_pixel(x,  y , PIXEL)


sh = sense_hat.SenseHat()
sh.set_rotation(0)
x, y = 1, 1
x_neu, y_neu = x, y
sh.set_pixels(LABYRINTH)

while True:
    sh = sense_hat.SenseHat()
    orientation   = sh.get_orientation()
    roll = (orientation["roll"] +90) % 360
    pitch = (orientation["pitch"]  +90) % 360
    #print(roll, pitch)
    if pitch > 100:
        x_neu = x - 1                # nach links
    elif pitch < 80:
        x_neu = x + 1                # nach rechts
    else:
        x_neu = x
    if roll > 100:
        y_neu = y + 1                # nach oben
    elif roll < 80:
        y_neu = y - 1                # nach unten
    else:
        y_neu = y

    refresh()
    time.sleep(ZEIT)












