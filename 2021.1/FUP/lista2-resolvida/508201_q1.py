import math

def circunferencia(r):
  return  2 * math.pi * r

def area(r):
  return math.pi * (r ** 2)

r = float(input('Entre com o valor do raio, para obter a circuferência e área do círculo: '))


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    print("A circuferência do círculo: {:.2f}".format(circunferencia(r)))
    print("A área do círculo: {:.2f}".format(area(r)))

