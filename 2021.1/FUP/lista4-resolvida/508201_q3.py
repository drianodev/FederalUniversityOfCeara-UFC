x = int(input("Digite o valor de x: "))
y = int(input("Digite o valor de y: "))

print("(", x, ",", y, ")")

if x > 0 and y > 0:
  print("Quadrante 1")
elif x < 0 and y > 0:
  print("Quadrante 2")
elif x < 0 and y < 0:
  print("Quadrante 3")
elif x > 0 and y < 0:
  print("Quadrante 4")