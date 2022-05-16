listas = [] # Lista onde entrará a lista cadastro[]

##################################################################################################################################
# Função cadastrar
def cadastrar():
    cadastro = [] # Lista pra adicionar o nome e quantidade
    nome_produto = input('Informe o nome do produto: ')
    qtd_produto = int(input('Informe a quantidade do produto: '))
    print('\n')
    
    for n in listas:
        for item in n:
            if nome_produto == item:
                print('Produto já cadastrado')
                print('\n')
                return menu()
                
    # Adiciona as variaveis na lista cadastro
    cadastro.append(nome_produto)
    cadastro.append(qtd_produto)

    # Adiciona a lista cadastro[] na lista listas[]
    listas.append(cadastro) 
    return menu()

##################################################################################################################################
##################################################################################################################################
# Função listar
def listar():
    op1 = 'nome'
    op2 = 'quantidade'
    opcao = input('Por nome ou quantidade? ')
    print('\n')

    # Lista por nome
    if opcao == op1:
        alfa_lista = sorted(listas) # Ordena em ordem alfabetica
        for n in alfa_lista:
            for exibe in  n:
                print(f'Produto: {n[0]}') # Exibe a lista em ordem alfabetica
                print(f'Quantidade: {n[1]}')
                break
    # Lista por quantidade            
    elif opcao == op2:
        qtd_lista = sorted(listas, key = lambda x: x[1], reverse=True) # Ordena em ordem decrescente
        for n in qtd_lista:
            for exibe in  n:
                print(f'Produto: {n[0]}') # Exibe a lista em ordem de quantidade
                print(f'Quantidade: {n[1]}')
                break
    else:
        print('Opção inválida.\n') 
    print('\n')
    return menu()

##################################################################################################################################
##################################################################################################################################
# Função buscar
def buscar():
    op1 = 'nome'
    op2 = 'quantidade'
    opcao = input('Buscar por nome ou quantidade? ')
    print('\n')

    contador = 1

    # Busca por nome
    if opcao == op1:
        # Item que deseja buscar
        desejado = input('Qual o nome do produto? ')
        print('\n')
        for n in listas:
            for item in n:
                if desejado == item:
                    print(f'Produto: {n[0]}') 
                    print(f'Quantidade: {n[1]}')
                    break
                elif contador > len(listas) or contador == len(listas):
                    print('O produto está indisponível')
                    break
                contador = contador + 1
                break

    # Busca por quantidade
    elif opcao == op2:
        # Quantidade que deseja buscar
        desejado = int(input('Informe a quantidade desejada para a busca: '))
        print('\n')
        qtd_lista = sorted(listas, key = lambda x: x[1]) # Ordena em ordem crescente
        for n in qtd_lista:
            for item in n:
                if desejado <= n[1]:
                    print(f'Produto: {n[0]}') 
                    print(f'Quantidade: {n[1]}')
                    break
                
                if contador > len(listas) or contador == len(listas):
                    print('O produto está indisponível')
                    break
                contador = contador + 1
                break
                
    else:
        print('Opção inválida.\n') 
    print('\n')
    return menu()

##################################################################################################################################
##################################################################################################################################
# Função atualizar
def atualizar():
    nome_pdt = input('Qual o produto? ')
    print('\n')

    contador = 1

    for n in listas:
        for item in n:
            if nome_pdt == item:
                nova_qtd = input('Qual a nova quantidade? ')
                # Define a nova quantidade
                n[1] = nova_qtd
                break
            elif contador > len(listas) or contador == len(listas):
                print('O produto está indisponível')
                break
            contador = contador + 1
            break

    print('\n')
    return menu()


##################################################################################################################################
##################################################################################################################################
# Função remover
def remover():
    nome_pdt = input('Qual o nome do produto a ser removido? ')
    print('\n')

    contador = 1

    for n in listas: 
        for item in n:
            if nome_pdt == item:
                # Remove a lista cadastro[] dentro de listas[]
                listas.remove(n)
                break
            elif contador > len(listas) or contador == len(listas):
                print('O produto está indisponível')
                break
            contador = contador + 1
            break

    print('\n')
    return menu()

##################################################################################################################################
##################################################################################################################################
# MENU
def menu():
    print('[C] Cadastrar\n[L] Listar\n[B] Buscar\n[A] Atualizar\n[R] Remover\n')
    cadastro = 'C'
    lista = 'L'
    busca = 'B'
    atualiza = 'A'
    remove = 'R'

    opcao = input('Escolha uma opção: ')
    print('\n')
    # Opções que retornam as funções
    if opcao == cadastro:
        return cadastrar()
    elif opcao == lista:
        return listar()
    elif opcao == busca:
        return buscar()
    elif opcao == atualiza:
        return atualizar()
    elif opcao == remove:
        return remover()
    else:
        print('Opção inválida')
    return menu()


if __name__ == '__main__':
    menu()

