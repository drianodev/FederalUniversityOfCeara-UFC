import pandas as pd
import matplotlib as mlp
import matplotlib.pyplot as plt


graduados = pd.read_csv('dado.csv', index_col = 0)

fig, ax = plt.subplots()

ax.bar(graduados.index, graduados['Hispanic'])
ax.set_xticks(graduados.index)
ax.set_xticklabels(graduados.index, rotation = 60, horizontalalignment = 'right')
ax.set_title('Número de hispânicos graduados de 1996 a 2012', fontsize = 16)
ax.set_ylabel('Número de graduados')

plt.show()

 

