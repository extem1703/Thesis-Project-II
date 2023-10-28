#! /usr/bin/python3

#Importando las librerías
import numpy as np
import matplotlib.pyplot as plt
import warnings
warnings.filterwarnings("ignore")

with open('Clean1.txt', 'r') as archivo:
    lineas = archivo.readlines()

#print(lineas)

strlista = "".join(lineas)

SHOWERS = strlista.split(' ========== ')

SHOWERS.pop(0)

lista_split_1 = []

for i in SHOWERS:
    firstsplit = i.split('\n ---------- ')
    lista_split_1.append(firstsplit)

LIST_ENERGY_INTERAC = []
LIST_NKG = []
LIST_PART_DISTR = []
LIST_ENERGY_DISTR = []
LIST_ENERGY_DEPOSIT = []

#########################
###Energy interaction:###
#########################

for i in range(100):
    LIST_ENERGY_INTERAC.append(lista_split_1[i][0])

STR_ENERGY_INTERAC = "".join(LIST_ENERGY_INTERAC)

with open("Files/Energy_interac.txt", 'w') as archivo:
    archivo.write(STR_ENERGY_INTERAC)

##########
###NKG:###
##########

for i in range(100):
    LIST_NKG.append(lista_split_1[i][1])

STR_NKG = "".join(LIST_NKG)

with open("Files/NKG.txt", 'w') as archivo:
    archivo.write(STR_NKG)

##################################
###Long. Particle distribution:###
##################################

for i in range(100):
    LIST_PART_DISTR.append(lista_split_1[i][2])

STR_PART_DISTR = "".join(LIST_PART_DISTR)

with open("Files/Particle_Distribution.txt", 'w') as archivo:
    archivo.write(STR_PART_DISTR)

################################
###Long. Energy distribution:###
################################

for i in range(100):
    LIST_ENERGY_DISTR.append(lista_split_1[i][3])

STR_ENERGY_DISTR = "".join(LIST_ENERGY_DISTR)

with open("Files/Energy_Distribution.txt", 'w') as archivo:
    archivo.write(STR_ENERGY_DISTR)

###########################
###Long. Energy Deposit:###
###########################

for i in range(100):
    LIST_ENERGY_DEPOSIT.append(lista_split_1[i][4])

STR_ENERGY_DEPOSIT = "".join(LIST_ENERGY_DEPOSIT)

with open("Files/Energy_Deposit.txt", 'w') as archivo:
    archivo.write(STR_ENERGY_DEPOSIT)
