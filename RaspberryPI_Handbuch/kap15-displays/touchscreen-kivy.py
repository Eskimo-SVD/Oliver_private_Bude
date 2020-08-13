#!/usr/bin/python3
# -*- coding: utf-8 -*-
import kivy
kivy.require('1.0.6')   # Ersetzen Sie dies mit Ihrer Kivy-Version

from kivy.app import App
from kivy.uix.togglebutton import ToggleButton
from kivy.uix.boxlayout import BoxLayout
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)
ledPin1 = 27
ledPin2 = 22

GPIO.setup(ledPin1, GPIO.OUT)
GPIO.setup(ledPin2, GPIO.OUT)
GPIO.output(ledPin1, GPIO.LOW)
GPIO.output(ledPin2, GPIO.LOW)

# Die Funktion von Button 1 wird definiert.
def led1(obj):
	if obj.state == "down":
		GPIO.output(ledPin1, GPIO.HIGH)
	else:
		GPIO.output(ledPin1, GPIO.LOW)

# Die Funktion von Button 2 wird definiert.
def led2(obj):
	if obj.state == "down":
		GPIO.output(ledPin2, GPIO.HIGH)
	else:
		GPIO.output(ledPin2, GPIO.LOW)

class MyApp(App):
    def build(self):
# Button 1 wird als Toggle-Button ausgeführt und mit der 
# Funktion led1() verknüpft. Gleiches gilt für Button 2.
 		button1 = ToggleButton(text="GPIO27")
		button1.bind(on_press=led1)	
		
		button2 = ToggleButton(text="GPIO22")
		button2.bind(on_press=led2)	

        # Die beiden Buttons werden dem Layout zugefügt.
		layout = BoxLayout(orientation='vertical')
		layout.add_widget(button1)
		layout.add_widget(button2)

		return layout

# Benutzeroberfläche starten
if __name__ == '__main__':
	MyApp().run()
