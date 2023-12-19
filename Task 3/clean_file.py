#! /usr/bin/python3

#Importando las librerías
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import warnings
warnings.filterwarnings("ignore")

with open('020014.sec', 'r') as archivo:
    lineas = archivo.readlines()

#print(lineas)

lista = []

for i in lineas:
    if len(i) > 80:
        lista.append(i)

#print(lista)

strlista = "".join(lista)

#print(strlista)

with open('Clean020014.sec', 'w') as archivo:
    archivo.write(strlista)
