a = int(input("Valor de a: "))
b = int(input("Valor de b: "))


def cubo(n: int) -> int:
    return n ** 3


def somatorio(a: int, b: int, f: "funcao") -> int:
    if a > b:
        return 0
    return f(a) + somatorio(a + 1, b, f)


print(somatorio(a, b, cubo))