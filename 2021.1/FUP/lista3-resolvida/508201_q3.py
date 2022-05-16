def sequencia(dna):
    str = dna
    C = str.count("C")
    G = str.count("G")
    T = str.count("T")
    A = str.count("A")

    percentual = (G + C / A + T + G + C) * 1

    return percentual

if __name__ == '__main__':
    dna = input("digite a sequência de dna: ")
    print("{:.1f}%".format(sequencia(dna)))

    #ACTGATCGATTACGTATAGTATTTGCTATCATACATATATATCGATGCGTTCAT