#!/usr/bin/python3
# Rechteck -Klasse
class Rechteck ():
    # Konstruktor
    def __init__ (self , laenge , breite ):
      self.laenge = laenge
      self.breite = breite

    # Getter und Setter für Länge
    @property
    def laenge (self):
      return self.__laenge
    @laenge .setter
    def laenge (self , laenge ):
      if laenge >0:
        self.__laenge =laenge
      else:
        raise ValueError ( 'Die Länge muss größer 0 sein. ')


    # Getter und Setter für Breite
    @property
    def breite (self):
      return self.__breite
    @breite .setter
    def breite (self , breite ):
      if breite >0:
        self.__breite =breite
      else:
        raise ValueError ( 'Die Breite muss größer 0 sein. ')


    # Methoden für Umfang und Fläche
    def umfang (self):
      return (self.__laenge + self.__breite ) * 2
    def flaeche (self):
      return self.__laenge * self.__breite

    # Fortsetzung des Klassencodes der Rechteck -Klasse
      # Operator Overloading für <, >, <=, >=, == und !=
      def __eq__ (self , other ):
        return self.flaeche () == other.flaeche ()
      def __lt__ (self , other ):
        return self.flaeche () < other.flaeche ()
      def __le__ (self , other ):
        return self.flaeche () <= other.flaeche ()


      # Umwandlung in Zeichenketten
      def __str__ (self):
        return 'R(%.1f,%.1f) ' % (self.laenge , self.breite )
      # für die Ausgabe durch print
      def __repr__ (self):
        return 'R(%.1f,%.1f) ' % (self.laenge , self.breite )


# Anwendung der Klasse
r1 = Rechteck (2, 4)
r2 = Rechteck (7, 12)
print(r1.flaeche (), r2.flaeche ()) # Ausgabe 8, 84
#if r2>r1:
#    print ("Der Flächeninhalt von r2 ist größer als der von r1.")
    
l = [ r2, r1, Rechteck (4 ,4) ]
print(sorted (l))
# Ausgabe [R(2.0 ,4.0) , R(4.0 ,4.0) , R(7.0 ,12.0)]