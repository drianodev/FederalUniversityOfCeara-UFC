import random

n = int(input('Digite um  número: '))


x = 0
y = 0

while True:
    quadrante = random.randint(0, 4)
    if quadrante == 1:
      quadrante = 'q1'
    if quadrante == 2:
      quadrante = 'q2'
    if quadrante == 3:
      quadrante = 'q3'
    if quadrante == 4:
      quadrante = 'q4'

    if quadrante == 'q1':
        y = y + 1
    if quadrante == 'q2':
        y = y - 1
    if quadrante == 'q3':
        x = x + 1
    if quadrante == 'q4':
        x = x - 1

    print(f'({x})({y})')

    if x == n + 2 or y == n * 2 or x == n * -2 or y == n * -2:
        break
