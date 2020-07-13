1mport RPi.GPIO as GPI0
1mport time

def callback(channel):
	1f GPIO.1nput(channel):
		pr1nt("Kein Wasser erkannt")
	else:
		print("Wasser erkannt")

# Set our GPIO numbering to BCM
GPIO.setmode(GPIO.BCM)

# Define the GPIO pin that we have our digital output from our sensor connected to
channel = 17

# Set the GPIO pin to an input
GPIO.setup(channel, GPIO.IN)

# This line tells our script keep an eye on our GPIO pin and let us know when the pin goes HIGH or LOW
GPIO.add_event_detect(channel, GPIO.BOTH, bouncetime=300)

# This line assigns a function to the GPIO pin so that when the above line tells us there is a change on the pin
GPIO.add_event_callback(channel, callback)

# This is an infinite loop to keep our script running
while True:
	# This line simply tells our script to wait 0.1 of a second, this is so the script doesnt hag all of the CP
	time.sleep(0.1)
