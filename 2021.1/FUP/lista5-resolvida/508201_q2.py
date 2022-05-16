isbn = input('Digite o número: ')


d1 = int(isbn[0])*10
d2 = int(isbn[1])*9
d3 = int(isbn[2])*8
d4 = int(isbn[3])*7
d5 = int(isbn[4])*6
d6 = int(isbn[5])*5
d7 = int(isbn[6])*4
d8 = int(isbn[7])*3
d9 = int(isbn[8])*2
Sum = (d1+d2+d3+d4+d5+d6+d7+d8+d9)
Mod = Sum%11
d10= 11 - Mod

ISBNNum=str(isbn)+str(d10)

print('O número do ISBN é: ' + ISBNNum)
