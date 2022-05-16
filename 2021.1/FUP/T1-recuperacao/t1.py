nPokebolas = int(input('Digite o número N de pokebolas: '))
g = int(input('Digite o valor da gravidade: '))
Xp = int(input('Digite a coordenada X (inteiro >= 0) do pokemon: '))
Yp = int(input('Digite a coordenada Y (inteiro >= 0) do pokemon: '))

# Variação de tempo
deltaT = 1
# Posição da bola
Xb = 1
Yb = 1

def jogo(nPokebolas):
  contador = 1
  # Instante T
  t = 0
  while contador <= nPokebolas:

    # Números de Tentativas
    print(f'Tentativa {contador}:')

    # Coordenadas do treinador
    Xt = int(input('Digite a coordenada X (inteiro >= 0) do treinador: '))
    Yt = int(input('Digite a coordenada Y (inteiro >= 0) do treinador: '))

    # Ponto de partida da pokebola (valor inicial do componente y da velocidade)
    Vybi = int(input('Digite o componente y da velocidade de lançamento: '))

    # Linhas contendo o instante t, a velocidade (vyb(t)) e as coordenadas xb(t) e yb(t) da pokebola
    print(f'>t=    {t}    vy=    {Vybi}    x=    {Xb}    y=    {Yb}')

    # Condições
    if Xb == Xp and Yb == Yp:
      # Para determinar se a bola atingiu o pokemon as coordenadas x e y da bola e do pokemon devem ser idênticas.
      print('A pokebola atingiu o pokemon.')
      break
    elif Yb <= 0:
      # A pokebola bater no chão
      print('A pokebola não atingiu o pokemon.')
    elif Xb >= Xp: 
      # A pokebola estar na mesma posição horizontal Xb que o pokemon (Xp), ou depois.
      print('A pokebola não atingiu o pokemon.')

    contador = contador + 1

  return nPokebolas

print(jogo(nPokebolas))
