#----------------------------------------------------
# Dateiname:  ring.py 
# Sounds abspielen mit PyGame
# Michael Weigend
# Raspberry Pi programmieren mit Python 3. Auflage, mitp 2015
# Kap. 4
# Michael Weigend 22. März 2016
#----------------------------------------------------
import pygame, random,time, os
from RPi import GPIO

pygame.mixer.pre_init(frequency=22050, size =-16,
                      channels=1, buffer=4096)
pygame.init()

soundfiles =["buzz.wav", "explosion.wav", "pop.wav"]
sounds  = [pygame.mixer.Sound(filename) for filename in soundfiles]
channel = pygame.mixer.Channel(1)


GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(10, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)


while True:
    if GPIO.input(10):
        sound = random.choice(sounds)
        channel.play(sound)
        time.sleep(0.5)
        
    
