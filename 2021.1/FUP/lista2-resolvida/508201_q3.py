valor1 = int(input('Entre com o primeiro valor: '))
valor2 = int(input('Entre com o segundo valor: '))
valor3 = int(input('Entre com o terceiro valor: '))

def ordena(x, y, z):
  x = max(valor1, valor2, valor3)
  y = min(valor1, valor2, valor3)
  z = (valor1 + valor2 + valor3) - x - y

  return y, z, x

if __name__ == '__main__':
    print("Os valores ordenados do menor para o maior são: ", ordena(valor1, valor2, valor3))
