palavra = input("digite a palavra: ")


def remove(palavra):
    return " ".join(palavra.split())


if __name__ == '__main__':
    print(remove(palavra))
