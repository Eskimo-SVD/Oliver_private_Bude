#!/usr/bin/python3
import time
import subprocess
import Adafruit_CharLCD as LCD

# Raspberry-Pi-Pins
lcd_rs      = 7
lcd_en      = 8
lcd_d4      = 25
lcd_d5      = 24
lcd_d6      = 23
lcd_d7      = 18

# Zeilen und Spalten für ein 16 x 2 LC-Display
lcd_columns = 16
lcd_rows    = 2
lcd = LCD.Adafruit_CharLCD(lcd_rs, lcd_en, lcd_d4, lcd_d5, 
                    lcd_d6, lcd_d7, lcd_columns, lcd_rows)
while True:
    zeit = time.strftime("%d.%b %H:%M:%S") 
    temp=subprocess.Popen("/opt/vc/bin/vcgencmd measure_temp", 
      shell=True, stdout=subprocess.PIPE).stdout.read()
    temp = (temp[5:9])
    lcd.message ("%s\nCPU-Temp: %s" %(zeit, float(temp)))
    time.sleep(5)
    lcd.home()