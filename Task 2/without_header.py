#! /usr/bin/python3

#Importando las librerías
import numpy as np
import matplotlib.pyplot as plt
import warnings
warnings.filterwarnings("ignore")

with open('01_multimu_out.txt', 'r') as archivo:
    lineas = archivo.readlines()

lista = []

for i in lineas:
    lista.append(i)

list_without_head = []

for i in range(len(lista)):
    if i > 248:
        list_without_head.append(lista[i])

strlista = "".join(list_without_head)

lineas = strlista.split(' PRESENT TIME : 24.05.2014  11:58:18 UTC\n AND RANDOM NUMBER GENERATOR AT BEGIN OF EVENT :     101')

lineas.pop(1)

strlista = "".join(lineas)

with open('Clean1.txt', 'w') as archivo:
    archivo.write(strlista)
