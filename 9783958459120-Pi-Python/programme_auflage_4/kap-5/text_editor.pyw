#!/usr/bin/python3
#----------------------------------------------------------------
# Dateiname: text_editor.pyw
# Texteditor mit Pulldown-Menü zum Löschen, zur Einstellung des Schrifttyps
# und zur Auswahl von Textbausteinen
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 5.8 
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
from tkinter import *

def format_text():
    font = selected_font.get()
    text.config(font=(font, 10))

def insert_phrase():
  text.insert(INSERT, selected_phrase.get())

def delete_text():
  text.delete(1.0, END)

window = Tk()
window.title("Texteditor")
scrollbar = Scrollbar(master=window)  
scrollbar.pack(side=RIGHT,fill =Y) 
text= Text(master=window, width = 30, height=5,
            wrap=WORD, font=('Arial', 10),
            yscrollcommand=scrollbar.set) 
text.pack(expand=1)
scrollbar.config(command=text.yview)

# Menü
menubar = Menu(master=window)               #1
window.config(menu=menubar)                 #2

# Löschen
menubar.add_command(label="Löschen",
                    command=delete_text)

# Menü Schrifttyp
font_menu = Menu(master=menubar)            #3
selected_font = StringVar()
menubar.add_cascade(label="Schrifttyp",
                    menu=font_menu)
for font in ["Arial", "Courier", "Times"]:
  font_menu.add_radiobutton(label=font,
             variable=selected_font, value=font,
             command=format_text)

# Menü Textbausteine
phrase_menu = Menu(master=menubar)            #3
selected_phrase = StringVar()
menubar.add_cascade(label="Textbausteine",
                    menu=phrase_menu)
phrases = ["Die frische Luft tut mir gut.",
           "Ich fühle mich großartig.",
           "Die Landschaft hier ist wunderbar."]

for ph in phrases:
  phrase_menu.add_radiobutton(label=ph,
             variable=selected_phrase, value=ph,
             command=insert_phrase)



window.mainloop()





                    
