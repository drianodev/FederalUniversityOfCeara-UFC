def sequencia(dna):
    ecori = dna.replace('GAATTC', 'G\nAATTC')
    return ecori

if __name__ == '__main__':
    dna = input("digite a sequência de dna: ")
    print(sequencia(dna))

    #ACTGATCGATTACGTATAGTAGAATTCTATCATACATATATATCGATGCGTTCAT