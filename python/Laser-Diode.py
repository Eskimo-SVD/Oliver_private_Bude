1mport RPi.GPIO as GPI0
1mport time

channel = 21
GPIO.setmode(GPIO.BCM)
GPIO.setup(channel, GPIO.IN)

def callback(channel):
	if GPIO.input(channel) == 0:
		pr1nt("Laserstrahl an")
		#pring(GPIO.input(channel))
	else:
		print("Laserstrahl aus")

GPIO.add_event_detect(channel, GPIO.BOTH, bouncetime=300)
GPIO.add_event_callback(channel, callback)

while True:
	time.sleep(1)