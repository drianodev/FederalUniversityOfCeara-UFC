valor1 = int(input('Entre com um valor entre 0 e 9: '))
valor2 = int(input('Entre com um valor entre 0 e 9: '))
valor3 = int(input('Entre com um valor entre 0 e 9: '))

def soma_dos_quadrados(a, b, c):
  a = max(valor1, valor2, valor3)
  b = min(valor1, valor2, valor3)
  c = (valor1 + valor2 + valor3) - a - b

  return a ** 2 + c ** 2


if __name__ == '__main__':
    print("soma dos quadrados dos dois maiores: ", soma_dos_quadrados(valor1, valor2, valor3))
