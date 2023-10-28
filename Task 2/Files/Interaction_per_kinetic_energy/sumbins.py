#! /usr/bin/python3

#Importando las librerías
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import warnings
warnings.filterwarnings("ignore")

# \\s+ denota uno o más caractéres de espacio en blanco
df = pd.read_table("Interaction_per_kinetic_energy.txt", sep="\\s+", header = None)

#iloc secciona el dataframe
DATA = df.iloc[:,:3]

DATA = DATA.to_numpy()

#Para seleccionar una columna se usa [:,i]

fil = len(DATA[:,0])
colum = len(DATA[0,:])

LOWER = np.zeros(40)
UPPER = np.zeros(40)
BIN = np.arange(1,41,1)

for i in range(fil):
    for k in BIN:
        if DATA[i][0] == k:
            LOWER[k-1] = LOWER[k-1] + DATA[i][1]
            UPPER[k-1] = UPPER[k-1] + DATA[i][2]

DATOS = np.hstack((BIN.reshape(-1,1), LOWER.reshape(-1,1), UPPER.reshape(-1,1)))

dfDATOS = pd.DataFrame(DATOS)

texto = dfDATOS.to_string(header=False, index=False, col_space=1)

with open('df_Inter_per_kin.txt', 'w') as archivo:
    archivo.write(texto)
