#! /usr/bin/python3

#Importando las librerías
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import warnings
warnings.filterwarnings("ignore")

df = pd.read_table("muons.csv", sep=",")

print(df)

texto = df.to_string(header=False, index=False, col_space=1)

with open('muons.txt', 'w') as archivo:
    archivo.write(texto)
