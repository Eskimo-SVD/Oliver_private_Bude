#----------------------------------------------------------------
# Dateiname: drum2.pyw
# Alternatives Modul zum Abspielen von Drumloops mit einer
# wav-Datei
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 8, Lösung 2
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
import pygame, random,time, os
from time import sleep
os.system ("amixer cset numid=3 1")
pygame.mixer.pre_init(frequency=22050, size =-16,
                      channels=1, buffer=4096)
pygame.init()


class Drum:
    def __init__ (self, bpm):
        self.sound = pygame.mixer.Sound("pop.wav")
        self.channel = pygame.mixer.Channel(1)
        self.channel.set_volume(1)
        self.time = 60 / bpm 
        self.running = False

    def play(self, pattern):
        self.running = True
        while self.running:
            for note  in  pattern:
               if note:
                   self.channel.play(self.sound)
                   sleep(note * self.time - self.sound.get_length())

    def stop(self):
        self.running = False
            

if __name__ == '__main__':
    d = Drum(30)
    d.play([1/2, 1/2, 1/4, 1/4])
    
        
        
        
    
