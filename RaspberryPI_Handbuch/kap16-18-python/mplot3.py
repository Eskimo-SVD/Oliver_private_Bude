#!/usr/bin/python3
import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.dates as mdates
from datetime import timedelta

# Daten einlesen
data = pd.read_csv('temp.txt',
                   parse_dates=[0],
                   sep='\t',
                   header=None,
                   names = ['datetime', 'temp'])

# Zeitspalte als Index verwenden
data.index = data['datetime']
del data['datetime']

# X-Achse bei 0:00, 3:00 ... 0:00 beschriften
mindate = data.index.min()
xticks = [ mindate.replace(hour=h, minute=0, second=0) 
           for h in range(0, 23, 3)]
last = mindate + timedelta(days=1)
xticks += [ last.replace(hour=0, minute=0, second=0) ]

# Diagramm erzeugen
fig, ax = plt.subplots(1)
ax.plot(data)
xfmt = mdates.DateFormatter('%H:%M')
ax.xaxis.set_major_formatter(xfmt)
plt.xticks(xticks)
ax.set(title='Temperatur [°C]')
ax.grid()
fig.savefig('plot3.png', dpi=200)
