import numpy as np

def imprimir(listaAdj):

    print('Lista de adjacência')

    for i in range(0, len(listaAdj)):
        print(f'{i + 1} -> {listaAdj[i]}')


def criarListaAdj(matriz, tipo):
    tam = len(matriz)
    lista = []
    for i in range(0, tam):
        ls = []
        lista.append(ls)

    if tipo == 'N':
        for i in range(0, len(lista)):
            for j in range(0, len(matriz[0])):
                if matriz[i][j] != 0:
                    lista[i].append(j+1)
    else:
        for i in range(0, len(lista)):
            for j in range(0, len(matriz[0])):
                if matriz[i][j] == -1:
                    lista[i].append(j + 1)


    return lista


def loadMatriz():
    nome = input("Digite o nome do arquivo: ")
    arquivo = open(nome, 'r')
    lista = arquivo.readlines() # ler todas as linhas e salva em listas

    for i in range(len(lista)):
        linha = lista[i].split()
        if i == 0:
            N = int(linha[0])
            matriz_adj = np.zeros( (N ,N),dtype =np.int64 ) 
            Ori = linha[2]        
        else:
            if Ori == "D":
                for k in range(0, len(lista)):
                    if k == int(linha[1]) - 1:
                        if matriz_adj[int(linha[0]) - 1, k] == 1 or matriz_adj[k, int(linha[0]) - 1] == -1:
                            matriz_adj[int(linha[0]) - 1, k] = -1
                        else:
                            matriz_adj[int(linha[0]) - 1, k] = -1
                            matriz_adj[k, int(linha[0]) - 1] = 1
            else:
                matriz_adj[int(linha[0])-1, int(linha[1])-1] = 1
                matriz_adj[int(linha[1])-1, int(linha[0])-1] = 1
    print(f'Matriz Adjacente:\n{matriz_adj}\n')
    listaAdj = criarListaAdj(matriz_adj, Ori)
    arquivo.close()

    imprimir(listaAdj)

loadMatriz()
