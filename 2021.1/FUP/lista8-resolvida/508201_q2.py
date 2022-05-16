def converte_vetor(vetor: list) -> dict:
  dicionario = {}
  for i in vetor:
    if i > 0:
      dicionario[vetor.index(i)] = i
  
  return dicionario


print(converte_vetor([1, 0, 0, 0, 0, 0, 3, 0, 0, 0]))