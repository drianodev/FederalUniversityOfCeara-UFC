#Em cada função abaixo programe o que está definido na docstring.
#Se seu código executar e imprimir no terminal a frase abaixo é porque passou em
#todos os testes.
#"Process finished with exit code 0"

#Questão 1: Lista
#Obs: quando função tem o retorno múltiplo, ela retorna uma tupla.
#Exemplo: a = [1,2,3] e b = [4,5,6]
#return a,b retornará ([1,2,3], [4,5,6])
from typing import ValuesView


def pares_e_impares(lista):
    """
    A função recebe um tipo list, lista, como parâmetro e retorna duas variáveis do tipo
    list cuja a primeira variável é uma lista dos elementos de lista com índices pares e
    a segunda é uma lista dos elementos de lista com índices ímpares. Por exemplo,
    pares_e_impares([1,2,3,4,5,4,3]) deve retornar a tupla ([1,3,5,3], [2,4,4]). Veja
    que o índice 0 é considerado par.

    >>> pares_e_impares([1,5,3,9,5,7,3])
    ([1, 3, 5, 3], [5, 9, 7])
    >>> pares_e_impares([1,5,1])
    ([1, 1], [5])
    >>> pares_e_impares([1,5])
    ([1], [5])
    >>> pares_e_impares([1])
    ([1], [])
    """
    i = 0
    a = []
    b = []

    while i < len(lista):
      if i % 2 == 0:
        a.append(lista[i])
      elif i % 2 != 0:
        b.append(lista[i])
      i = i + 1
    tupla = (a, b)
    return tupla


#Questão 2: Lista
#Nesta questão você não pode usar for. Se usar não ganhará os pontos dela.
def primeiro_float(lista):
    """
    O parâmetro lista é uma lista de floats. A função deve retornar o índice do
    primeiro elemento de lista que tem um componente não zero após o decimal. Isto é,
    o primeiro elemento que não representa um inteiro. Se não houver tal elemento,
    a função deve retornar -1. Por exemplo, primeiro_float([1.0, 2.0, 1.0, 1.5, 2.0])
    retornará 3, porque 1.5 não representa inteiro.

    >>> primeiro_float([1.0, 2.0, 1.0, 1.5, 2.0])
    3
    >>> primeiro_float([1.5, 2.0, 1.0, 1.5, 2.0])
    0
    >>> primeiro_float([1.0, 2.0, 1.0, 1.0, 2.01])
    4
    >>> primeiro_float([1.0, 2.0, 1.0, 1.0, 2.0])
    -1
    """
    i = 0

    while i < len(lista):
      if lista[i] != int(lista[i]):
        b = i
        break
      i = i + 1
      if len(lista) < i+1:
        b = -1
        break
    
    a = b
    return a


#Questão 3: Dicionário
def somente_inteiro(dicionario):
    """
    dicionário é um dict cujos valores podem ser de qualquer tipo. Retorne um novo
    dicionário que contém apenas os pares de chave-valor de dicionario cujos valores
    são do tipo int. Por exemplo, somente_inteiro({5: [2,3], 4: 5, 20: '1'}) retornaria
    {4: 5}.

    >>> somente_inteiro({5: [2,3], 4: 5, 20: '1'})
    {4: 5}
    >>> somente_inteiro({5: [2,3], 4: 5.7, 20: '1'})
    {}
    """
    count = 0
  
    for key, value in dicionario.items():
      if type(value) == int:
        b = {key: value}
        break
      count = count +1
      if len(dicionario) < count+1:
        b = {}
    a = b
    return a


#Questão 4: arquivo
def artilheiros_temporada(nome_arquivo):
    """
    A string nome_arquivo é o nome de um arquivo que armazena o número de gols marcados por
    cada jogador em uma temporada. Cada total de gols é armazenado em uma linha diferente como
    um valor seguido pelo caractere g (por exemplo: 34g). Retorne o número de jogadores que
    marcaram mais de 20 gols em uma temporada.
    >>> artilheiros_temporada('teste1.txt')
    2
    >>> artilheiros_temporada('teste2.txt')
    0
    """
    numJogador = []

    arquivo = open(nome_arquivo, 'r') 
    for linha in arquivo.readlines():
      num = []
      newLinha = int(linha.replace("g", "").strip())
      
      if newLinha > 20:
        num.append(newLinha)
        numJogador.append(num)
    
    return len(numJogador)

if __name__ == '__main__':
    import doctest
    doctest.testmod()
