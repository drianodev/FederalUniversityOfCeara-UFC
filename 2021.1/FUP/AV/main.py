#Em cada função abaixo programe o que está definido na explicação e docstring.
#Se seu código executar e imprimir no terminal a frase abaixo é porque passou em
#todos os testes.
#"Process finished with exit code 0"

#Questão 1: String, For
#A questão abaixo pede para você encriptar uma mensagem.
#Encriptar é esconder a mensagem original em outra.
#O procedimento para encriptar a mensagem 'hello world' é:
# 'h' ocorre na posição 21 do código do teste, que corresponde
# a letra 'u' no alfabeto regular disponibilizado na descrição.
# 'e' ocorre na posição 24 do código do teste, que corresponde
# a letra 'x' no alfabeto regular disponibilizado na descrição.
# Esse procedimento ocorre para toda letra da mensagem.
def encripta(mensagem, codigo):
    '''(str, str) -> str
    Retorne a mensagem criptografada usando o código fornecido.
    O código é uma ordem do alfabeto mais os caracteres espaço e '.'.
    A posição de cada caractere na string de código fornece o
    índice do caractere de substituição no alfabeto regular
    'abcdefghijklmnopqrstuvwxyz .'
    >>> encripta('hello world', '. zyxwvutsrqponmlkjihgfedcba')
    'uxqqnbfnkqy'
    >>> encripta('mensagem', '. zyxwvutsrqponmlkjihgfedcba')
    'pxoj.vxp'
    >>> encripta('', '. zyxwvutsrqponmlkjihgfedcba')
    ''
    '''
    # INVERTE O CODIGO
    alfabeto = codigo[::-1]
    lista = []

    for i in mensagem:
        # PEGA A POSIÇÃO DA LETRA NO CODIGO INVERTIDO     
        posicao_alfabeto = alfabeto.index(i)
        # ATRIBUI A LETRA NA POSIÇÃO DO CODIGO A VARIAVEL 'a'
        a = codigo[posicao_alfabeto]
        # ADICIONA 'a' A UMA LISTA
        lista.append(a)
    # DESMEMBRA A LISTA PARA SE TORNAR UMA STRING
    mensagem_encripitada = "".join(lista)

    return mensagem_encripitada

#Questão 2: Lista
def string_lista(L):
    '''(list de str) -> list de list
    A função string_lista recebe uma lista L de strings com o formato:
    'nome, nota, nota, nota, ...'. Ela deve retornar uma lista de listas,
    onde cada lista interna tem o formato: [nome, nota, nota, nota, ...].
    Nome é uma string e nota é um float.

    >>> string_lista(['Ana, 50, 90, 80', 'João, 60, 70', 'Carla, 98.5, 100, 95.5, 98'])
    [['Ana', 50.0, 90.0, 80.0], ['João', 60.0, 70.0], ['Carla', 98.5, 100.0, 95.5, 98.0]]
    >>> string_lista(['Ana, 50, 90, 80'])
    [['Ana', 50.0, 90.0, 80.0]]
    >>> string_lista(['Ana, 50, 90, 80', 'João, 60, 70', 'Carla, 98.5'])
    [['Ana', 50.0, 90.0, 80.0], ['João', 60.0, 70.0], ['Carla', 98.5]]
    '''
    lista = []
  
    for i in L:
        # LER A VARIAVEL 'L' E SEPARA POR VIRGULA E ADICIONA A UMA LISTA
        a = i.split(', ')
        lista.append(a)
    # CONTADOR VAI ACESSAR AS POSIÇÕES
    contador = 0
    while contador < len(lista):
        # ADICIONA A LISTA DENTRO DA LISTA TRANSFORMANDO OS NUMEROS EM FLOAT
        lista[contador][1:] = [float(k) for k in lista[contador][1:]]
        contador += 1    
        

    return lista

#Questão 3: Dicionário
#Considere um dicionário onde cada chave é uma tupla de 3 elementos contendo o
#nome de uma equipe esportiva, sua cidade e seu esporte, e cada valor é o
#número de vitórias dessa equipe. Por exemplo:
#d = {(’Fortaleza’, ’Fortaleza’, ’futebol’): 10,
#     (’Carcará’, ’Fortaleza’, ’basquetebol’): 15,
#     (’Corinthians’, ’São Paulo’, ’futebol’): 9,
#     (’Sesi’, ’Bauru’, ’vôlei’): 3}
#O cabeçalho da função obtem_vitorias_por_categoria aparece abaixo. Possui dois parâmetros:
# - um dicionário como o acima.
# - a categoria, que é uma string: 'nome', 'cidade' ou 'esporte'.
#obtem_vitorias_por_categoria retorna um novo dicionário baseado no dicionário
#passado por parâmetro, no qual as chaves são os nomes, cidades ou esportes
#(conforme especificado por categoria) e os valores são o número total de vitórias
#associadas a cada chave.
def obtem_vitorias_por_categoria(time_para_vitoria: dict, categoria: str):
    '''
    Para cada tupla chave em time_para_vitoria, busque a entrada correspondente à categoria.
    Essas entradas devem ser chaves do dicionário a ser retornado. O valor dessa chave é a
    soma de todos os valores onde a entrada apareceu em time_para_vitoria.

    >>> obtem_vitorias_por_categoria({('Fortaleza', 'Fortaleza', 'futebol'): 10,('Carcará', 'Fortaleza', 'basquetebol'): 15,('Corinthians', 'São Paulo', 'futebol'): 9,('Sesi', 'Bauru', 'vôlei'): 3}, 'esporte')
    {'futebol': 19, 'basquetebol': 15, 'vôlei': 3}
    >>> obtem_vitorias_por_categoria({('Fortaleza', 'Fortaleza', 'futebol'): 10,('Carcará', 'Fortaleza', 'basquetebol'): 15,('Corinthians', 'São Paulo', 'futebol'): 9,('Sesi', 'Bauru', 'vôlei'): 3}, 'nome')
    {'Fortaleza': 10, 'Carcará': 15, 'Corinthians': 9, 'Sesi': 3}
    >>> obtem_vitorias_por_categoria({('Fortaleza', 'Fortaleza', 'futebol'): 10,('Carcará', 'Fortaleza', 'basquetebol'): 15,('Corinthians', 'São Paulo', 'futebol'): 9,('Sesi', 'Bauru', 'vôlei'): 3}, 'cidade')
    {'Fortaleza': 25, 'São Paulo': 9, 'Bauru': 3}
    '''
    dicionario_resultado = {}
    if categoria == 'esporte':
        # PERCORRER AS CHAVES E VALORES DO DICIONARIO
        for key, value in time_para_vitoria.items():
            # SE A CHAVE QUE ESTOU PERCORRENDO JÁ EXISTIR NO DICIONARIO
            if key[2] in dicionario_resultado:
                # VOU PERCORRER O DICIONARIO RESULTADO
                for key2 in dicionario_resultado:
                    # QUANDO AS DUAS FOREM IGUAIS
                    if key2 == key[2]:
                        # ADICIONO A SOMA DOS VALORES DA DUAS CHAVES A MINHA CHAVE ORIGINAL, NO CASO A PRIMEIRA APARIÇÃO DA CHAVE
                        dicionario_resultado[key2] = value + dicionario_resultado[key2]    
            else:
                dicionario_resultado[key[2]] = value
    elif categoria == 'nome':
        # PERCORRER AS CHAVES E VALORES DO DICIONARIO
        for key, value in time_para_vitoria.items():
            # SE A CHAVE QUE ESTOU PERCORRENDO JÁ EXISTIR NO DICIONARIO
            if key[0] in dicionario_resultado:
                # VOU PERCORRER O DICIONARIO RESULTADO
                for key2 in dicionario_resultado:
                    # QUANDO AS DUAS FOREM IGUAIS
                    if key2 == key[0]:
                        # ADICIONO A SOMA DOS VALORES DA DUAS CHAVES A MINHA CHAVE ORIGINAL, NO CASO A PRIMEIRA APARIÇÃO DA CHAVE
                        dicionario_resultado[key2] = value + dicionario_resultado[key2]    
            else:
                dicionario_resultado[key[0]] = value
    elif categoria == 'cidade':
        # PERCORRER AS CHAVES E VALORES DO DICIONARIO
        for key, value in time_para_vitoria.items():
            # SE A CHAVE QUE ESTOU PERCORRENDO JÁ EXISTIR NO DICIONARIO
            if key[1] in dicionario_resultado:
                # VOU PERCORRER O DICIONARIO RESULTADO
                for key2 in dicionario_resultado:
                    # QUANDO AS DUAS FOREM IGUAIS
                    if key2 == key[1]:
                        # ADICIONO A SOMA DOS VALORES DA DUAS CHAVES A MINHA CHAVE ORIGINAL, NO CASO A PRIMEIRA APARIÇÃO DA CHAVE
                        dicionario_resultado[key2] = value + dicionario_resultado[key2]    
            else:
                dicionario_resultado[key[1]] = value

    return dicionario_resultado

#Questão 4: arquivo
#Você pode presumir que todas as funções estão formatadas de forma exata e correta:
#Um espaço após o def, nenhum espaço antes do (.
def nome_funcao(nome_arquivo):
    """
    A função nome_funcao recebe a string nome_arquivo, que é o nome de um arquivo código fonte, 
    como parâmetro e retorna uma lista contendo todo nome de função encontrado no arquivo.
    Caso o arquivo não tenha função definida, a lista retornada é vazia.
    >>> nome_funcao('respostas_p2.py')
    ['pares_e_impares', 'primeiro_float', 'somente_inteiro', 'artilheiros_temporada']
    >>> nome_funcao('condicionais.py')
    ['categoria_tempestade', 'mensagem_categoria', 'aviso']
    >>> nome_funcao('vazio.py')
    []
    """
    lista_resultado = []
    lista_auxiliar = []
     # Abre o arquivo e adicionar cada linha a lista
    with open(nome_arquivo, 'r') as arquivo:
        for i in arquivo.readlines():
            if 'def' in i:
                lista_auxiliar.append(i)
    
    for j in lista_auxiliar:
        # SEPARA PRIMEIRO AS LINHAS QUE CONTEM DEF, E DEPOIS SEPARA A '(' OU SEJA, ANTES DOS PARAMESTROS
        a = j.strip('def ')
        b = a.split('(')
        for k in b:
            # SE NÃO TIVER ')' OU '#' ADICIONA A UMA LISTA
            if (not ')' in k) and (not '#' in k):
                lista_resultado.append(k)

    return lista_resultado

if __name__ == '__main__':
    import doctest
    doctest.testmod(verbose=True)

