hrs = int(input("Quantas horas o carro ficou estacionado? "))
minutos = int(input("Quantos minutos o carro ficou estacionado? "))

hrs_convertidas = hrs * 60

hrs_e_min = hrs_convertidas + minutos

hora = 60

# Variaveis contendo o valor por hrs_e_min
hr1 = 2.0
hr2 = 1.5
a_partir = 1.0

#condições
if hrs_e_min <= hora:
  print("Pague R$", hr1)
elif hrs_e_min > hora and hrs_e_min <= hora*2:
  print("Pague R$", hr1 + hr2)
elif hrs_e_min > hora*2:
  if minutos == 60:
    print("Pague R$", hr1 + hr2 + a_partir)
  elif minutos == 30:
    print("Pague R$", hr1 + hr2 + a_partir/2)