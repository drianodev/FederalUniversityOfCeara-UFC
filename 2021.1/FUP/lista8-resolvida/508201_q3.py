def adiciona_vetores(vetor1: dict, vetor2: dict) -> dict:

  dicionario = {}
  dicionario1 = {}
  dicionario2 = {}

  for key1, value1 in  vetor1.items():
    for key2, value2 in vetor2.items():
      if key1 == key2:
        soma = value1 + value2
        dicionario1[key1] = soma
        dicionario = dicionario1
      else:
        dicionario2[key1] = value1
        dicionario2[key2] = value2
        a = sorted(dicionario2.items())
        dicionario = dict(a)

  return dicionario

print(adiciona_vetores({0: 1, 6: 3}, {0: 2, 6: 4}))
print(adiciona_vetores({0: 1, 6: 3}, {3: 2, 8: 4}))