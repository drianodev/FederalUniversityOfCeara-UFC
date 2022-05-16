seq_num = input('Digite a sequencia de numeros: ')
C = int(input('Digite o número: '))

seq_lista = seq_num.split(',')
lista = list(map(int, seq_lista))

for i in lista[::1]:
  aux = C // i
  if i * aux == C and i != aux and aux in lista:
    print(f'Resultado: {i} e {aux}')
    break
  elif i == lista[-1]:
    print('Resultado: não existem tais números')
    break
  else:
    continue