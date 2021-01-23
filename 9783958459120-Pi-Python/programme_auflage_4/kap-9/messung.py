import ndir                   #1   
import time                   #2
sensor = NDIR.Sensor(0x4D)    #3  
sensor.begin()                
while True:                   #4
    sensor.measure()          #5
    print(sensor.ppm)         #6
    time.sleep(0.5)           #7
