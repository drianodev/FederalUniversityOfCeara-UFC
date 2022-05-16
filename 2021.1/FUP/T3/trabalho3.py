nome = ''
data = ''
nome_exercicio = ''
peso = 0

def carrega_arquivo(nome_arquivo: str) -> None:
    '''
    Esta função adiciona as informações do arquivo denominado nome_arquivo às suas estruturas de
    dados para que as chamadas subsequentes às outras funções possam retornar
    os valores corretos. Nao retorna nada
    ''' 
    global nome
    global data
    global nome_exercicio
    global peso

    lista1 = []
    lista2 = []
    lista3 = []
    lista4 = []

    # Abre o arquivo e adicionar cada linha a lista
    with open(nome_arquivo, 'r') as arquivo:
        for i in arquivo:
            i = ''.join(i.split("\n"))
            if '-' in i:
                lista2.append(i)
            elif 'Peso' in i:
                lista3.append(i)
            elif 'kg' in i:
                lista4.append(i)
            else:    
                lista1.append(i)

    nome = str(lista4).strip('[]')
    data = str(lista2).strip('[]')
    nome_exercicio = str(lista1).strip('[]') + str(lista2).strip('[]') + str(lista3).strip('[]') + str(lista4).strip('[]')
    peso = lista3
    
##################################################################################################################

def pega_exercicios(nome: str, data: str) -> list:
    '''
    Uma lista de todos os nomes de exercícios realizados por nome na data.
    Pode retornar uma lista vazia.
    '''
    lista_final = []

    lista_pega_exercicio = []

    lista_nome = nome.split(',')
    lista_data = data.split(',')

    for j in lista_nome:
        if ':' in j:
            a = j.strip(" ':0123456789kg")
            lista_pega_exercicio.append(a)
    
    indice1 = 2
    indice2 = 0

    for l in lista_data:
        a = l.strip(" '")
        lista_final.append(a)
        
        for k in lista_pega_exercicio[indice2:indice1]:
            lista_final.append(k)
        indice1 += 2
        indice2 += 2
            

    return lista_final

##################################################################################################################

def pega_conjunto_exercicios(nome: str, data: str, nome_exercicio: str) -> list:
    '''
    Retorna uma lista representando os conjuntos de nome_exercicio realizados por nome na data.
    Cada elemento da lista é uma tupla de dois elementos.
    O primeiro elemento é um float que representa o peso do exercício em kg.
    O segundo é um int que representa o número de repetições naquele peso.
    Pode retornar uma lista vazia.
    '''
    lista_nome = nome.split(',')
    lista_data = data.split(',')
    lista_nome_exercicio = nome_exercicio.split(',')

    lista_alfanum = []

    lista_pesos = []
    lista_repeticoes = []

    # LIMPA A LISTA ATÉ SOBRAR APENAS OS NÚMEROS REFERENTES AO PESO E REPETIÇÃO
    for i in lista_nome:
        a = i.split(';')
        for j in a:
            b = j.split(" ")
            for l in b:
                c = l.split("'")
                for k in c:
                    if k.isalnum() == True or k.isdigit() == True:
                        lista_alfanum.append(k)
        
    for j in lista_alfanum:
        if 'kg' in j:
            a = j.strip('kg')
            b = float(a)
            lista_pesos.append(b)
        else:
            c = int(j)
            lista_repeticoes.append(c)

    
    zipped = zip(lista_pesos, lista_repeticoes)

    tupla = list(zipped)
   
    return tupla

##################################################################################################################

def pega_treino(nome: str, data: str) -> list:
    '''
    Retorna uma representação do treino realizado por nome na data.
    Pode retornar uma lista vazia.
    Cada exercício do treino é representado por uma string que é o nome do exercício e uma lista.
    Cada elemento da lista é uma tupla de dois elementos. 
    O primeiro elemento é um float que representa o peso do exercício em kg. 
    O segundo é um int que representa o número de repetições naquele peso.
    '''
    lista_nome = nome.split(',')
    lista_data = data.split(',')

    lista_alfanum = []

    lista_pesos = []
    lista_repeticoes = []

    # LIMPA A LISTA ATÉ SOBRAR APENAS OS NÚMEROS REFERENTES AO PESO E REPETIÇÃO
    for i in lista_nome:
        a = i.split(';')
        for j in a:
            b = j.split(" ")
            for l in b:
                c = l.split("'")
                for k in c:
                    if k.isalnum() == True or k.isdigit() == True:
                        lista_alfanum.append(k)
        
    for j in lista_alfanum:
        if 'kg' in j:
            a = j.strip('kg')
            b = float(a)
            lista_pesos.append(b)
        else:
            c = int(j)
            lista_repeticoes.append(c)
    
    zipped = zip(lista_pesos, lista_repeticoes)

    tupla = list(zipped)

    # LIMPA A LISTA ATÉ SOBRAR APENAS OS NOMES REFERENTES AOS EXERCICIOS
    lista_exercicio = []
    for k in lista_nome:
        b = k.strip(" '")
        c = b.split(':')
        for l in c:
            if l.isalpha() == True:
                lista_exercicio.append(l)

    lista_final = []

    for l in lista_exercicio:
        lista_final.append(l)
        if l == 'Agachamento':
            lista_final.append(tupla[:7])
        elif l == 'Flexoes':
            lista_final.append(tupla[7:10])
        elif l == 'Supino':
            lista_final.append(tupla[17:19])


    return lista_final
           
##################################################################################################################

def max_peso_exercicio(nome_exercicio: str) -> tuple:
    '''
    o nome e a data da pessoa que teve o maior peso em nome_exercicio, junto com o peso.
    '''
    lista_nome_exercicio = nome_exercicio.split("'")
    
    nome = []
    lista_data = []
    lista_exercicios = []

    # VERIFICAR LISTA PARA LIMPAR E DEIXAR NOME, DATA E EXERCICIOS
    for i in lista_nome_exercicio:
        if i == lista_nome_exercicio[1]:
            nome.append(i)
        elif '-' in i:
            lista_data.append(i)
        elif ':' in i:
            lista_exercicios.append(i)

    lista_peso = []
    # LIMPA A LISTA ATÉ SOBRAR APENAS OS NÚMEROS REFERENTES AO PESO
    for j in lista_exercicios:
        if ';' in j:
            a = j.split(';')
            for k in a:
                b = k.split(',')
                for l in b:
                    c = l.split(' ')
                    for m in c:
                        if 'kg' in m:
                            d = m.strip('kg')
                            e = float(d)
                            lista_peso.append(e)
    # PEGAR O MAIOR PESO
    maior_peso = max(lista_peso, key=float)
    
    # DATA DO MAIOR PESO
    data = []
    for i in lista_data:
        if maior_peso in lista_peso[:7]:
            data.append(i)
        elif maior_peso in lista_peso[7:10]:
            data.append(i)
        elif maior_peso in lista_peso[17:19]:
            data.append(i)

    tupla = (nome[0], data[0], maior_peso)

    return tupla 

##################################################################################################################

def max_peso_total(nome_exercicio: str) -> tuple:
    '''
    Retorna o nome, data e peso levatado por uma pessoa no 
    nome_exercicio (contando todas as repetições em uma única série)
    em todas as séries e repetições de um determinado exercício em um dia. 
    Portanto, se para o supino, a pessoa A levantasse 100 kg 3 vezes e a pessoa B levantasse 75 kg 5 vezes,
    essa função retornaria: 
    ('B', '11-11-2010 ', 375,0) (assumindo que B realizou este treino em 11 de novembro de 2010). 
    Esta função pesquisa em todas as datas possíveis.
    '''
    lista_nome_exercicio = nome_exercicio.split("'")

    nome = []
    lista_data = []
    lista_exercicios = []

    # VERIFICAR LISTA PARA LIMPAR E DEIXAR NOME, DATA E EXERCICIOS
    for i in lista_nome_exercicio:
        if i == lista_nome_exercicio[1]:
            nome.append(i)
        elif '-' in i:
            lista_data.append(i)
        elif ':' in i:
            lista_exercicios.append(i)
    
    lista_peso_repeticoes = []
    # LIMPA A LISTA ATÉ SOBRAR APENAS OS NÚMEROS REFERENTES AO PESO
    for j in lista_exercicios:
        if ';' in j:
            a = j.split(';')
            for k in a:
                b = k.split(',')
                for l in b:
                    c = l.split(' ')
                    for m in c:
                        if m.isalnum() == True:
                            if 'kg' in m:
                                d = m.strip('kg')
                                e = float(d)
                                lista_peso_repeticoes.append(e)
                            else:
                                e = int(m)
                                lista_peso_repeticoes.append(e)
    
    # MULTIPLICANDO OS VALORES
    lista_float = []
    lista_inteiros = []
    for k in lista_peso_repeticoes:
        if type(k) == float:
            lista_float.append(k)
        else:
            lista_inteiros.append(k)

    produto = [x * y for x, y in zip(lista_float,lista_inteiros)]
    
    # PEGAR O MAIOR VALOR
    maior_valor = max(produto, key=float)

    # DATA DO MAIOR PESO
    data = []
    for i in lista_data:
        if maior_valor in produto[:7]:
            data.append(i)
        elif maior_valor in produto[7:10]:
            data.append(i)
        elif maior_valor in produto[17:19]:
            data.append(i)
    
    tupla = (nome[0], data[0], maior_valor)

    return tupla

##################################################################################################################

def max_peso_data(data: str, peso: float) -> list:  
    '''
    Retorna uma lista de nomes cujo peso corporal era menor que o peso na data
    '''
    lista_data = data.split(',')
    lista_peso = peso

    lista_final = []
    for i in lista_peso:
        a = i.split(' ')
        for j in a:
            if 'kg' in j:
                b = j.strip('kg')
                lista_final.append(b)
    
    # PEGAR O MENOR VALOR
    menor_valor = f'Peso: {min(lista_final, key=int)}kg'
    
    resultado = [menor_valor]

    return resultado
    
##################################################################################################################

if __name__ == "__main__":
    pass