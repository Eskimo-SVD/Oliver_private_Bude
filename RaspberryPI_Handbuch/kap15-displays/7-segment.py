#!/usr/bin/python3
from Adafruit_LED_Backpack import SevenSegment
import subprocess, time
display = SevenSegment.SevenSegment()
display.begin()

while True:
	# Anzeige der CPU-Temperatur
	temp = subprocess.Popen("/opt/vc/bin/vcgencmd measure_temp", 
      shell=True, stdout=subprocess.PIPE).stdout.read()
	temp = (temp[5:9])
	display.print_float(float(temp))
	display.set_colon(False)
	display.write_display()
	time.sleep(2)		
	
	#Anzeige der Uhrzeit
	display.clear()	
	zeit = time.strftime("%H%M")	
	display.print_float(int(zeit), decimal_digits = 0, 
                        justify_right=False)
	display.set_colon(True)
	display.write_display()
	time.sleep(2)