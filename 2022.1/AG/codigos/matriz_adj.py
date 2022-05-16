import numpy as np

def imprime(N,mat):
    for i in range(N):
        for j in range(N):
            print(mat[i,j],end=' ')
        print()        
    
def loadMatriz():
    nome = input("Digite o nome do arquivo: ")
    arquivo = open(nome, 'r')
    lista = arquivo.readlines()# ler todas as linhas e salva em listas
   
    for i in range(len(lista)):
        linha = lista[i].split()
        if i == 0:
            N = int(linha[0])
            matriz_adj = np.zeros( (N ,N),dtype =np.int64 ) 
            Ori = linha[2]        
        else:
            if Ori == "D":
            	matriz_adj[ int(linha[0])-1,int(linha[1])-1] = int (linha[2])
            else:
                matriz_adj[ int(linha[0])-1,int(linha[1])-1] = 1
                matriz_adj[ int(linha[1])-1,int(linha[0])-1] = 1
    #arquivo.close()
    print(matriz_adj)
    imprime(N,matriz_adj)

loadMatriz()    
