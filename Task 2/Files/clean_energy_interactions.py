#! /usr/bin/python3

#Importando las librerías
import numpy as np
import matplotlib.pyplot as plt
import warnings
warnings.filterwarnings("ignore")

with open('Energy_interac.txt', 'r') as archivo:
    lineas = archivo.readlines()

strlista = "".join(lineas)

SHOWERS = strlista.split('SHOWER NO')

SHOWERS.pop(0)

#La información que se quiere está en la posición 4i+3

lista_split_1 = []

for i in range(len(SHOWERS)):
    if i%4 == 3:
        lista_split_1.append(SHOWERS[i])

strlista1 = '\n'.join(lista_split_1)

INTERAC_KIN = strlista1.split('\n\n\n')

lista_split_2 = []

for i in range(len(INTERAC_KIN)):
    if i%3 == 1:
        lista_split_2.append(INTERAC_KIN[i])

strlista2 = '\n'.join(lista_split_2)

INTERAC_KIN_CLEAN = strlista2.split('\n\n')

strlista3 = '\n'.join(INTERAC_KIN_CLEAN)

INTERAC_KIN_CLEAN_FIN = strlista3.split('\n')

lista_split_3 = []

for i in range(len(INTERAC_KIN_CLEAN_FIN)):
    if i%42 != 0 and i%42 != 1:
        lista_split_3.append(INTERAC_KIN_CLEAN_FIN[i])

strlista4 = '\n'.join(lista_split_3)

with open('Interaction_per_kinetic_energy/Interaction_per_kinetic_energy.txt', 'w') as archivo:
    archivo.write(strlista4)
