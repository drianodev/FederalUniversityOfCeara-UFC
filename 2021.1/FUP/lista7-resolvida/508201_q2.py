import numpy as np
n = input('Digite a sequencia de numeros: ')

n_lista = n.split(',')
v = list(map(int, n_lista))


def matriz(v):
  # Gerar e preencher matriz
  matriz = []
  for i in range(len(v)):
    linha = []
    for j in range(len(v)):
      aux = np.gcd(v[i], v[j])
      if aux > 1:
        linha.append(0)
      else:
        linha.append(1)
    matriz.append(linha)
  matrix = np.matrix(matriz)
  
  return matrix

print(matriz(v))
