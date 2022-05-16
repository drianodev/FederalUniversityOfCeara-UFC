def constroi_vocabulario(frase: str) -> None:
  dicionario = {}
  dicionario1 = {}
  dicionario2 = {}

  frase_esp = frase.split(' ')
  
  # PALAVRAS
  for palavras in frase_esp :
    contagem = dicionario1.get(palavras, 0)
    contagem += 1
    dicionario1[palavras] = contagem

  # LETRAS
  for letras in frase:
    contagem = dicionario2.get(letras, 0)
    contagem += 1
    dicionario2[letras] = contagem
  
  dicionario = {'Palavras': dicionario1, 'Letras': dicionario2}
  

  return dicionario


print(constroi_vocabulario('isso e um teste az teste isso'))