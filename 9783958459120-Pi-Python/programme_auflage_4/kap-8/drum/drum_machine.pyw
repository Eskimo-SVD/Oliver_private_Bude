#----------------------------------------------------------------
# Dateiname: drum_machine.pyw
# Editor für Drumloops mit GUI
#
# Michael Weigend: Raspberry Pi programmieren mit Python, 3. Auflage
# mitp 2016
# Kap. 8 Lösung 2
# 29.3. 2016
#----------------------------------------------------------------
from drum2 import Drum
from tkinter import *
import _thread

BEAT = 0.1
NOTES = ['halbe.gif', 'viertel.gif', 'achtel.gif', 'blank.gif']
class Note(Label):  
    def __init__(self, master):
        Label.__init__(self, master=master, bg='white')
        self.images = [PhotoImage(file=i) for i in NOTES]
        self.index = 0  
        self.values =[1.0/2, 1.0/4, 1.0/8, 0]  
        self.config(image=self.images[0],
                    width='1cm', height ='1.5cm')
        self.bind('<1>', self.next_)   

    def next_(self, event):
        if self.index < 3:                              #5
             self.index += 1
        else: self.index = 0
        self.config(image=self.images[self.index])      #6
            
    def value(self):
        return self.values[self.index]                  #7

class DrumMachine:
    def __init__(self):
        self.window = Tk()
        self.drum = Drum(20)                            #8
        self.notes = [Note(self.window) for i in range(8)]
        for note in self.notes:                         #9
                note.pack(side=LEFT)
        self.buttonPlay = Button(master=self.window,
                                 text='Play', command=self.play) #10
        self.buttonStop = Button(master=self.window,
                                 text='Stop', command=self.drum.stop) #11
        self.buttonPlay.pack(side=LEFT, fill=Y)
        self.buttonStop.pack(side=LEFT, fill=Y)
        self.window.mainloop()
        
    def play(self):
        pattern = [note.value() for note in self.notes]
        if not self.drum.running:                      #12
            _thread.start_new_thread(self.drum.play,(pattern,))

            
DrumMachine()
    
