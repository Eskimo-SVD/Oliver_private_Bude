#!/usr/bin/python3
import numpy as np
import matplotlib.pyplot as plt
x = np.linspace(0, 2 * np.pi, 1000)
y = np.sin(x)
plt.plot(x, y)
plt.savefig('sinus-highres.png', dpi=200)  # 1280 x 960 Px.
