#!/usr/bin/python3
import numpy as np
import matplotlib.pyplot as plt
x = np.linspace(- np.pi, 5 * np.pi, 1000)
y = np.sin(x)
fig, ax = plt.subplots()
ax.plot(x, y)
ax.set(xlabel='x', ylabel='sin(x)', 
       title='Sinus-Kurve')
ax.grid()
fig.savefig('plot2.png', dpi=200) 
