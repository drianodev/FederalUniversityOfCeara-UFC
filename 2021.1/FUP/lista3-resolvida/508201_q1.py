palavra1 = input("digite a primeira palavra: ")
palavra2 = input("digite a segunda palavra: ")


def anagrama(palavra1, palavra2):
    if sum(ord(x) for x in palavra1) == sum(ord(x) for x in palavra2):
        print("Anagramas!")
    else:
        print("Não são anagramas!")

if __name__ == '__main__':
    print(anagrama(palavra1, palavra2))