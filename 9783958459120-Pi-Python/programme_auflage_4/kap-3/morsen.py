#----------------------------------------------------------------
# Dateiname: morsen.py
# Text durch Morsezeichen darstellen.
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 3.13
# Michael Weigend 20. April 2016
#--------------------------------------------------------------


morse = {"a":".-", "b":"-...", "c":"-.-.", "d":"-..",
         "e":".", "f": "..-.", "g":"--.", "h":"....",
         "i":"..", "j":".---", "k":"-.-", "l":".-..",
         "m":" --", "n":"-.", "o":"---", "p":".--.",
         "q":"--.-", "r":".-.", "s":"...", "t":"-",
         "u":"..-", "v":"...-", "w":".--", "x":"-..-",
         "y":"-.--", "z":"--..", "ä":".-.-", "ö":"---.",
         "ü":"..--", "ß":"...--.", " ":" "}           #1

text = input("Geben Sie einen Text ein: ")
morsetext = []
for buchstabe in text:                                #2
    if buchstabe in morse.keys():
        morsetext.append(morse[buchstabe])            #3

for m in morsetext:
    print(m, end=" ")

         



    
