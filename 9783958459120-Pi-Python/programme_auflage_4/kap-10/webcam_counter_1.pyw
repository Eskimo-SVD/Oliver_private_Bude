#--------------------------------------------------------------
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 10
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
from tkinter import Canvas, Tk, Label, TOP, LEFT
import io, random,_thread
from urllib.request import urlopen
from time import sleep, asctime
from PIL import Image, ImageTk, ImageDraw

URL = "http://www.vz.hessen.de/res/webcams/ALL/imgstadion.jpg"
THRESHOLD = 40
MIN_SIZE = 20
HOTSPOT = (70, 130, 140, 180)                        #1

class Webcam:    
  def __init__(self, url, hotspot):
    self.url, self.hotspot = url, hotspot
    self.new, self.old = None, None                  #2  

  def newImage (self):
    self.old = self.new                              #3
    f = urlopen(self.url)
    img = f.read()                    
    f.close()
    img1 = Image.open(io.BytesIO(img))               #4
    draw = ImageDraw.Draw(img1)
    draw.rectangle(self.hotspot, outline="white")    #5
    self.new = img1.crop(self.hotspot)               #6             
    return ImageTk.PhotoImage(img1)                  #7

  def checkTraffic(self):                      
    if self.new and self.old:                        #8
        changedPix = 0
        o, n = self.old.load(), self.new.load()     #9
        width, height = self.old.size
        for x in range(width):                      #10
           for y in range(height):
               diff = abs(o[x, y][1] - n[x, y][1])
               if diff > THRESHOLD:
                  changedPix += 1
        return changedPix > MIN_SIZE                #11

class App:
  def __init__(self, url, hotspot):
    self.webcam = Webcam(url, hotspot)
    self.window = Tk()
    self.labelPhoto = Label(master=self.window)     #12
    self.labelCounter = Label(master=self.window,
                               text="Verkehr: - %  ")
    self.labelFeedback = Label(master=self.window,
                               width=20) 
    self.labelPhoto.pack(side=TOP)
    self.labelCounter.pack(side=LEFT)
    self.labelFeedback.pack(side=LEFT)
    _thread.start_new_thread(self.count, ())        #13
    self.window.mainloop()

  def count(self):   
    while True:
      self.count = 0
      for i in range(10):
        img = self.webcam.newImage()
        self.labelPhoto.config(image=img)
        if self.webcam.checkTraffic():
          self.count +=1
          self.labelFeedback.config(
                          text="Bewegung erkannt")
        else:
          self.labelFeedback.config(text="")
        sleep(30) 
      verkehr = "Verkehr:" + str(self.count * 10) + "%"
      self.labelCounter.config(text=verkehr) 
 
App(URL, HOTSPOT)
