#! /usr/bin/python3

#Importando las librerías
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import warnings
warnings.filterwarnings("ignore")

df = pd.read_table("df_Inter_per_kin.txt", sep="\\s+", header = None)

DATA = df.iloc[:,:3]

DATA = DATA.to_numpy()

LOWER = DATA[:,1]
UPPER = DATA[:,2]

h_llim = -0.0e14
h_ulim = 1.025e14
numbins = 41

bin_range = (h_llim, h_ulim)

plt.hist(LOWER, bins = numbins, range = bin_range, color = 'blue', edgecolor = 'black' , alpha = 0.5, label = 'LOWER')
plt.hist(UPPER, bins = numbins, range = bin_range, color = 'red', edgecolor = 'black' , alpha = 0.5, label = 'UPPER')
plt.title('Histograma')
plt.xlabel('Energy (GeV)')
plt.ylabel('Frecuency')
plt.legend()
plt.savefig('histograma_Python.png')
plt.show()
