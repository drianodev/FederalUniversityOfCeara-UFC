x0 = int(input('Entre com o valor de x0: '))
y0 = int(input('Entre com o valor de y0: '))
x1 = int(input('Entre com o valor de x1: '))
y1 = int(input('Entre com o valor de y1: '))
x2 = int(input('Entre com o valor de x2: '))
y2 = int(input('Entre com o valor de y2: '))
x3 = int(input('Entre com o valor de x3: '))
y3 = int(input('Entre com o valor de y3: '))


def cruza(x0, y0, x1, y1, x2, y2, x3, y3) -> bool:
  print("primeiro retângulo", "(", x0, ",", y0, ")(", x1, ",", y1,")", "|", "segundo retângulo", "(", x2, ",", y2, ")(", x3, ",", y3,")")
  return not (x1 < x2 or x0 > x3 or y1 > y3 or y0 > y3)

if __name__ == '__main__':
    print(cruza(x0, y0, x1, y1, x2, y2, x3, y3))
