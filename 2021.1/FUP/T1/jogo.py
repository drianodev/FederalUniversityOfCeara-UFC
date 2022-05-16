""" Trabalho 1: Programa principal do quebra-cabeça de frases """

import random
from typing import List

import auxiliares as auxf
from constantes import (PRECO_VOGAL, BONUS_CONSOANTE, JOGADOR_UM,
                        JOGADOR_DOIS, CONSOANTE, VOGAL, RESOLVER, SAIR,
                        HUMANO, HUMANO_HUMANO, HUMANO_COMPUTADOR, FACIL, DIFICIL,
                        TODAS_CONSOANTES, TODAS_VOGAIS,
                        PRIORIDADE_CONSOANTES, ESCONDIDA)


################################ O Jogo: #################################
def jogar(quebra_cabeca: str, quebra_cabecas: List[str], tipo_jogo: str) -> None:
    """Jogue!"""

    visao = constroi_visao(quebra_cabeca)
    consoantes, vogais = TODAS_CONSOANTES, TODAS_VOGAIS
    pontuacao_jogador_um, pontuacao_jogador_dois = 0, 0
    jogador_atual = JOGADOR_UM
    dificuldade = FACIL

    if tipo_jogo == HUMANO_COMPUTADOR:
        dificuldade = seleciona_dificuldade_computador()

    movimento = ''
    while not auxf.e_fim_de_jogo(quebra_cabeca, visao, movimento):
        pontuacao = auxf.pontuacao_jogador_atual(pontuacao_jogador_um,
                                                 pontuacao_jogador_dois,
                                                 jogador_atual)
        num_ocorrencias = 0

        mostra_menu_de_movimentos(jogador_atual, pontuacao, visao)

        if auxf.e_humano(jogador_atual, tipo_jogo):
            (movimento, palpite) = humano_movimentar(pontuacao, consoantes, vogais)
        else:
            (movimento, palpite) = computador_movimentar(visao, quebra_cabecas, dificuldade,
                                                         consoantes)

        if movimento == SAIR:
            print('Sua escolha foi sair do jogo!')
            vencedor = 'Sem Vencedor'

        if movimento == RESOLVER:
            if palpite == quebra_cabeca:
                pontuacao = calcular_pontuacao(quebra_cabeca, visao, consoantes, pontuacao)
                visao = quebra_cabeca
                vencedor = jogador_atual
            else:
                print("A solução '{}' é incorreta. Continue jogando!" \
                      .format(palpite))

        else:  # palpite VOGAL or CONSOANTE
            visao = atualizar_visao(quebra_cabeca, visao, palpite)
            num_ocorrencias = quebra_cabeca.count(palpite)
            pontuacao = auxf.calcula_pontuacao(pontuacao, num_ocorrencias, movimento)

            consoantes = auxf.apague(consoantes, consoantes.find(palpite))
            vogais = auxf.apague(vogais, vogais.find(palpite))

            vencedor = jogador_atual

            print("{} palpita {}, que ocorre {} vez(es) no quebra cabeça."
                  .format(jogador_atual, palpite, num_ocorrencias))
            print("Pontuação de {} é {}.".format(jogador_atual, pontuacao))

        if jogador_atual == JOGADOR_UM:
            pontuacao_jogador_um = pontuacao
        else:
            pontuacao_jogador_dois = pontuacao
        jogador_atual = auxf.proximo_jogador(
            jogador_atual, num_ocorrencias, tipo_jogo)

    # Jogo acabou.
    mostra_resultado(vencedor, quebra_cabeca, tipo_jogo, pontuacao_jogador_um,
                     pontuacao_jogador_dois)


def atualizar_visao(quebra_cabeca: str, visao: str, palpite: str) -> str:
    """ Retorna uma nova visão de quebra_cabeca: uma visão em que cada ocorrência
    de palpite em quebra_cabeca é revelada.

    >>> atualizar_visao('apple', '^^^le', 'a')
    'a^^le'
    >>> atualizar_visao('apple', '^^^le', 'p')
    '^pple'
    >>> atualizar_visao('apple', '^^^le', 'z')
    '^^^le'

    """

    nova_visao = ''
    for indice in range(len(quebra_cabeca)):
        nova_visao += auxf.atualizar_visao_caractere(quebra_cabeca, visao, indice, palpite)
    return nova_visao


def calcular_pontuacao(quebra_cabeca: str, visao: str, consoantes_nao_adivinhadas: str,
                       pontuacao_atual: int) -> int:
    """ Retorna a pontuação final, calculada adicionando constantes.BONUS_CONSOANTE pontos
    a <pontuacao_atual> para cada ocorrência de cada letra em <consoantes_nao_adivinhadas>
    no quebra_cabeca que aparece como constants.ESCONDIDA em visao.

    >>> calcular_pontuacao('apple pies', '^pple p^es', 'dfkpqstz', 0)
    0
    >>> calcular_pontuacao('apple pies', '^^^le ^^e^', 'dfkpqstz', 0)
    8

    """

    pontuacao_final = pontuacao_atual
    for letra in consoantes_nao_adivinhadas:
        if auxf.e_letra_bonus(letra, quebra_cabeca, visao):
            pontuacao_final += BONUS_CONSOANTE * quebra_cabeca.count(letra)
    return pontuacao_final


########################## Jogadas: Movimento Computador #######################
def computador_movimentar(visao: str, quebra_cabecas: List[str], dificuldade: str,
                          consoantes: str) -> (str, str):
    """ Retorna o próximo movimento do computador:

    (constantes.RESOLVER, suposição de solução) ou (constantes.CONSOANTE, suposição de letra)
    Se a dificuldade for constantes.DIFICIL, o computador escolhe resolver se pelo menos metade
    das letras em exibição são reveladas (não constantes.ESCONDIDAS). Caso contrário, o computador
    opta por adivinhar uma consoante.
    """

    if auxf.computador_escolhe_resolver(visao, dificuldade, consoantes):
        movimento = RESOLVER
        palpite = retorna_correspondencia(visao, quebra_cabecas)
        print('\tEscolho resolver: {}.'.format(palpite))
    else:
        movimento = CONSOANTE
        palpite = computador_palpita_letra(consoantes, dificuldade)
        print('\tEscolho como palpite a letra: {}.'.format(palpite))
    return movimento, palpite


def retorna_correspondencia(visao: str, quebra_cabecas: List[str]) -> str:
    """ Retorna um quebra-cabeça de <quebra_cabecas> que poderia ser representado por <visao>.
    Se esse quebra-cabeça não existir, retorne a string vazia.

    >>> retorna_correspondencia('^^ ro^k^', ['sta', 'cs rocks', 'math is cool'])
    'cs rocks'
    >>> retorna_correspondencia('^^ ro^ks', ['sta', 'pineapples', 'math is cool'])
    ''S
    """

    for quebra_cabeca in quebra_cabecas:
        if corresponde(quebra_cabeca, visao):
            return quebra_cabeca
    return ''


def corresponde(quebra_cabeca: str, visao: str) -> bool:
    """ Retorna True se e somente se visao for visao válida de quebra_cabeca.

    >>> corresponde('', '')
    True
    >>> corresponde('a', 'a')
    True
    >>> corresponde('bb', 'b^')
    False
    >>> corresponde('abcde', 'ab^^e')
    True
    >>> corresponde('axyzb', 'ab^^e')
    False
    >>> corresponde('abcdefg', 'ab^^e')
    False
    """

    if len(quebra_cabeca) != len(visao):
        return False

    for indice in range(len(quebra_cabeca)):
        if quebra_cabeca[indice] != visao[indice] and \
                not auxf.e_escondida(indice, quebra_cabeca, visao):
            return False
    return True


def computador_palpita_letra(consoantes: str, dificuldade: str) -> str:
    """ Retorna a letra de consoantes. Se dificuldade é constants.FACIL,
        selecione a letra aleatoriamente. Se dificuldade é constants.DIFICIL,
        selecione a primeira letra de constants.PRIORIDADE_CONSOANTES que
        ocorre em consoantes.

        len(consoantes) > 0;
        ao menos um caractere em consoantes está em
        consoantes.PRIORIDADE_CONSOANTES.

        dificuldade em (constants.FACIL, constants.DIFICIL).

    >>> computador_palpita_letra('bcdfg', 'H')
    'd'

    """

    if dificuldade == DIFICIL:
        for CONSOANTE in PRIORIDADE_CONSOANTES:
            if CONSOANTE in consoantes:
                return CONSOANTE
    return random.choice(consoantes)


########################## Jogadas: humano ####################
def humano_movimentar(pontuacao_jogador: int, consoantes: str, vogais: str) -> tuple:
    """ Pede ao usuário para fazer um movimento:

        1) Pede repetidamente para escolher um movimento (constants.CONSOANTE,
        constants.VOGAL, constants.RESOLVER ou constants.SAIR), até uma entrada
        válida ser fornecida.

        2) Após receber constants.VOGAL ou constants.CONSOANTE,
        pede repetidamente para escolher uma letra correspondente, até uma
        entrada válida ser fornecida.

        3) Após receber constants.RESOLVER, pergunta por uma palavra solução.

        Retorna o palpite do usuário ou uma string vazia representando
        a escolha constants.SAIR.
    """

    palpite = ''
    movimento = selecionar_movimento(pontuacao_jogador, consoantes, vogais)

    if movimento == SAIR:
        palpite = ''
    if movimento == VOGAL:
        palpite = selecionar_letra(vogais)
    if movimento == CONSOANTE:
        palpite = selecionar_letra(consoantes)
    if movimento == RESOLVER:
        palpite = input('Informe seu palpite: ')

    return (movimento, palpite)


def selecionar_movimento(pontuacao: int, consoantes: str, vogais: str) -> str:
    """ Pedir repetidamente ao jogador atual que escolha um movimento, até uma
        alternativa válida ser feita. Retorna o movimento selecionado. Validade do
        movimento é definida por e_movimento_valido(tipo-movimento, pontuacao, consoantes,
        vogais).

        Observação: Exemplos Docstring não fornecidos desde que o resultado
        depende do dado de entrada.

    """

    menu = constroi_menu_de_opcoes()

    movimento = input(menu)
    while not e_movimento_valido(movimento.strip(), pontuacao, consoantes, vogais):
        movimento = input(menu)

    return movimento.strip()


def selecionar_letra(letras: str) -> str:
    """ Pede repetidamente ao usuário por uma letra, até receber uma entrada válida.
        Returna a letra. Opções válidas são caracteres de <letras>.

        Observação: Exemplos Docstring não fornecidos desde que o resultado
        depende do dado de entrada.
    """

    prompt = 'Escolha letra de [{}]: '.format(
        ','.join(['{}'] * len(letras)))
    opcoes_validas = tuple(letras)
    return pede_por_selecao(prompt, opcoes_validas)


def pede_por_selecao(formato_prompt: str, opcoes_validas: tuple) -> str:
    """ Pede repetidamente ao usuário por uma seleção, até uma das opcoes_validas
        ser fornecida. O menu do usuário é criado como formato_prompt.format(opcoes_validas).
        Retorna a entrada do usuário com espaços em branco removidos das extremidades.

        Observação: Exemplos Docstring não fornecidos desde que o resultado
        depende do dado de entrada.

    """

    menu = formato_prompt.format(*opcoes_validas)

    selecao = input(menu)
    while selecao.strip() not in opcoes_validas:
        selecao = input('Escolha inválida.\n{}'.format(menu))

    return selecao.strip()


def mostra_menu_de_movimentos(jogador_atual: str, pontuacao_jogador: int, visao: str) -> None:
    """ Exibe um menu para o jogador selecionar o próximo movimento. """

    print('=' * 50)
    print('{}, é sua vez. Você tem {} pontos.'.format(
        jogador_atual, pontuacao_jogador))
    print('\n' + visao + '\n')


def constroi_menu_de_opcoes() -> str:
    """ Retorne um menu para o jogador selecionar o próximo movimento. """

    menu = '''Selecione o tipo de movimento:
    [{}] - VOGAL,
    [{}] - CONSOANTE,
    [{}] - RESOLVER,
    [{}] - SAIR.\n'''.format(VOGAL, CONSOANTE, RESOLVER, SAIR)

    return menu


def e_movimento_valido(movimento: str, pontuacao: int, consoantes: str, vogais: str) -> bool:
    """ Retorna se movimento é valido. Se invalido, imprime mensagem explicativa.
        Um movimento é válido quando:

        1) movimento é um de constants.CONSOANTE, constants.VOGAL,
        constants.RESOLVER ou constants.SAIR;

        2) Se movimento é constants.VOGAL, pontuacao é grande o suficiente para comprar uma
        VOGAL (ao menos constants.PRECO_VOGAL), e vogais tem ao menos um caractere.

        3) Se movimento pe constants.CONSOANTE, consoantes tem ao menos um caractere.

    >>> e_movimento_valido('X', 0, '', '')
    Movimentos válidos são: C, V, R e S.
    False
    >>> e_movimento_valido('S', 0, '', '')
    True
    >>> e_movimento_valido('R', 42, 'bdfrt', 'aeui')
    True
    >>> e_movimento_valido('C', 2, 'bcdfghjklmnpqstvwxyz', 'aeiou')
    True
    >>> e_movimento_valido('C', 2, '', 'aeiou')
    Você não tem mais consoantes para palpitar!
    False
    >>> e_movimento_valido('V', 1, 'bcdfghjklmnpqstvwxyz', 'aeiou')
    True
    >>> e_movimento_valido('V', 0, 'bcdfghjklmnpqstvwxyz', 'aeiou')
    Você não tem pontos suficientes para revelar uma VOGAL. Vogais custam 1 ponto(s).
    False
    >>> e_movimento_valido('V', 42, 'bcdfghjklmnpqstvwxyz', '')
    Você não tem mais vogais para palpitar!
    False

    """

    if movimento not in (CONSOANTE, VOGAL, RESOLVER, SAIR):
        print('Movimentos válidos são: {}, {}, {}, and {}.'.format(
            CONSOANTE, VOGAL, RESOLVER, SAIR))
        return False

    if movimento == VOGAL and pontuacao < PRECO_VOGAL:
        print('Você não tem pontos suficientes para revelar uma vogal. '
              'Vogais custam {} ponto(s).'.format(PRECO_VOGAL))
        return False

    if movimento == VOGAL and vogais == '':
        print('Você não tem mais vogais para palpitar!')
        return False

    if movimento == CONSOANTE and consoantes == '':
        print('Você não tem mais consoantes para palpitar!')
        return False

    return True


############################# Configuração do Jogo: #############################
def selecionar_tipo_de_jogo() -> str:
    """ Pedir ao usuário repetidamente por um tipo de jogo, até uma entrada válida
        ser fornecida. Retorna o tipo de jogo. Opções válidas são constants.HUMANO,
        constants.HUMANO_HUMANO e constants.HUMANO_COMPUTADOR.

        Observação: Exemplos Docstring não fornecidos desde que o resultado
        depende do dado de entrada.

    """

    menu = '''Escolha um tipo de jogo:
     [{}] - Um jogador
     [{}] - HUMANO-HUMANO
     [{}] - HUMANO-COMPUTADOR\n'''
    opcoes_validas = HUMANO, HUMANO_HUMANO, HUMANO_COMPUTADOR
    return pede_por_selecao(menu, opcoes_validas)


def seleciona_dificuldade_computador() -> str:
    """ Pede repetidamente por uma dificuldade do computador, até uma entrada válida ser fornecida.
        Retorna a dificuldade do computador. Opções válidas são constants.FACIL e constants.DIFICIL.

        Observação: Exemplos Docstring não fornecidos desde que o resultado
        depende do dado de entrada.

    """

    menu = 'Escolha a dificuldade do jogo ([{}] - FACIL ou [{}] - DIFICIL): '
    opcoes_validas = FACIL, DIFICIL
    return pede_por_selecao(menu, opcoes_validas)


def constroi_visao(quebra_cabeca: str) -> str:
    """ Retorna uma string que é baseada em quebra_cabeca, com cada caractere
        substituido por constants.ESCONDIDA.

    >> > constroi_visao('apple cake is great! #rus008')
    '^^^^^ ^^^^ ^^ ^^^^^! #^^^008'
    >> > constroi_visao('108@#$&')
    '108@#$&'

    """

    visao = ''
    for char in quebra_cabeca:
        if char.isalpha():
            visao = visao + ESCONDIDA
        else:
            visao = visao + char
    return visao


############################# Fim de Jogo: #############################
def mostra_resultado(vencedor: str, quebra_cabeca: str, tipo_jogo: str,
                     pontuacao_jogador_um: int, pontuacao_jogador_dois: int) -> None:
    """ mostra resultado do jogo: quem venceu e qual placar final. """

    print('E o vencedor é... {}!'.format(vencedor))
    print('A solução para o quebra cabeça deste jogo é: {}.'.format(quebra_cabeca))
    if auxf.e_jogo_de_um_jogador(tipo_jogo):
        print('Neste jogo, o jogador marcou {} ponto(s)'.
              format(pontuacao_jogador_um))
    else:
        print('Neste jogo, {} marcou {} e {} marcou {} ponto(s)'.
              format(JOGADOR_UM, pontuacao_jogador_um, JOGADOR_DOIS,
                     pontuacao_jogador_dois))


############################# O programa: #############################
if __name__ == '__main__':

    import doctest

    doctest.testmod()

    ARQUIVO_DE_DADOS = 'jogo-pequeno.txt'

    QUEBRA_CABECAS = []
    with open(ARQUIVO_DE_DADOS) as arquivo_de_dados:
        for linha in arquivo_de_dados:
            QUEBRA_CABECAS.append(linha.lower().strip())

    QUEBRA_CABECA = random.choice(QUEBRA_CABECAS)

    print('Bem vindo ao quebra-cabeça de frases!')

    print('***' + QUEBRA_CABECA + '***')

    TIPO_JOGO = selecionar_tipo_de_jogo()
    jogar(QUEBRA_CABECA, QUEBRA_CABECAS, TIPO_JOGO)
