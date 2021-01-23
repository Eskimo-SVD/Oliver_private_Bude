#----------------------------------------------------------------
# Dateiname: sound.py
# Klänge abspielen
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 3.12
# Michael Weigend 20. April 2016
#--------------------------------------------------------------

import pygame, random, time
from RPi import GPIO
pygame.mixer.pre_init()
pygame.init()                                          #2
soundfiles = {"buzz.wav", "explosion.wav",
              "singer.wav"}                            #3
sounds = [pygame.mixer.Sound(filename) for filename in soundfiles]
GPIO.setwarnings(False)                                #4
GPIO.setmode(GPIO.BOARD)
GPIO.setup(10, GPIO.IN)
while True:
    if GPIO.input(10):
        sound = random.choice(sounds)                  #5
        sound.play()                                   #6
        time.sleep(0.5)                                #7
