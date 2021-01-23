#----------------------------------------------------------------
# Dateiname: color.py
# Modul mit Klasse Color. Objekte dieser Klasse repräsentieren Farben.
# 
# Michael Weigend
# Raspberry Pi programmieren mit Python, 4. Auflage, mitp 2018
# Kap. 10
# Michael Weigend 20. September 2018
#--------------------------------------------------------------
# color.py
class Color (object):
  def __init__(self, r, g, b):
    self.r, self.g, self.b = r, g, b

  def __add__(self, other): 
    r, g, b = self.r + other.r, self.g + other.g,self.b + other.b
    r, g, b = min (r, 255), min (g, 255), min (b, 255)
    return Color(r, g, b)

  def __sub__(self, other): 
    r, g, b = self.r - other.r, self.g - other.g, self.b - other.b
    r, g, b = max (r, 0), max (g, 0), max (b, 0)
    return Color(r, g, b)

  def __lt__(self, other): 
    return(self.r < other.r) and (self.g < other.g) and \
         (self.b < other.b)

  def __gt__(self, other):  
    return(self.r > other.r) and (self.g > other.g) and \
          (self.b > other.b)

  def __str__ (self):
        return "<color {} {} {}>".format(self.r, self.g, self.b)
  
    
if __name__ == "__main__":
    red = Color(255, 0, 0)
    grey = Color(120, 120, 120)
    lightGrey = Color(200, 200, 200)
    green = Color (0, 255, 0)
    print (red + grey)
    print (red - grey)
    print (red + green)
    print (lightGrey > grey)
    
    
  
    
