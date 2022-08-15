def loadlista():
    nome = input("Digite o nome do arquivo: ")
    arquivo = open(nome, 'r')
    lista = arquivo.readlines() # ler todas as linhas e salva em lista
    for i in range(len(lista)):
        linha = lista[i].split()
        if i == 0:
            N = int(linha[0])    
            lista_adj = [[] for _ in range(N)] # criando uma lista de lista
            Ori = linha[2] 
        else:
      	    if Ori == "D":
      	    	lista_adj[int(linha[0])-1].append(int(linha[1])-1)
      	    else:
            	lista_adj[int(linha[0])-1].append(int(linha[1])-1)
            	lista_adj[int(linha[1])-1].append(int(linha[0])-1)
    return lista_adj,N
