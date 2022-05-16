def subsequente(palavra1, palavra2):
    len_palavra1 = len(palavra1)
    len_palavra2 = len(palavra2)
    index_palavra1 = 0
    index_palavra2 = 0

    while index_palavra1 < len_palavra1 and index_palavra2 < len_palavra2:
        if palavra1[index_palavra1] == palavra2[index_palavra2]:
            index_palavra1 += 1
            index_palavra2 += 1
            print(palavra1 + " é uma subsequência de " + palavra2)
        else:
            print(palavra1 + " não é uma subsequência de " + palavra2)
        return index_palavra1 == len_palavra1


if __name__ == '__main__':
    palavra1 = input("digite a primeira palavra: ")
    palavra2 = input("digite a segunda palavra: ")
    print(subsequente(palavra1, palavra2))
