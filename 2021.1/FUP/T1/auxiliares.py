""" Trabalho 1: Funções auxiliares ao jogo """

from constantes import *


# Esta função é dada como exemplo
def e_vitoria(quebra_cabeca: str, visao: str) -> bool:
    """ Retorna True se e somente se quebra_cabeca e visao formam uma combinação vencedora.
        Isto é, se e somente se quebra_cabeca e visao são iguais.

    >>> e_vitoria('banana', 'banana')
    True
    >>> e_vitoria('apple', 'a^^le')
    False
    >>> e_vitoria('apple', 'app')
    False

    """

    return quebra_cabeca == visao


# Esta função é dada como exemplo de uso de uma função auxiliar.
def e_fim_de_jogo(quebra_cabeca: str, visao: str, movimento: str) -> bool:
    """ Retorna True se e somente se quebra_cabeca e visao são uma combinação vencedora
        ou movimento é SAIR.

    >>> e_fim_de_jogo('apple', 'a^^le', 'V')
    False
    >>> e_fim_de_jogo('apple', 'a^^le', 'Q')
    False
    >>> e_fim_de_jogo('apple', 'apple', 'S')
    True

    """

    return movimento == SAIR or e_vitoria(quebra_cabeca, visao)


# Esta função precisa ser implementada. Deixada como exemplo para guiar a inserção de outras.
def e_humano(jogador_atual: str, tipo_jogo: str) -> bool:
    """ Retorna True se e somente se jogador_atual representa um HUMANO em
        um jogo do tipo tipo_jogo.

        jogador_atual é JOGADOR_UM ou JOGADOR_DOIS.
        tipo_jogo é HUMANO, HUMANO_HUMANO ou HUMANO_COMPUTADOR.

        Em jogo HUMANO ou em jogo HUMANO_HUMANO, um jogador sempre é
        HUMANO. Em jogo HUMANO_COMPUTADOR, JOGADOR_UM é HUMANO e
        JOGADOR_DOIS é computador.

    >>> e_humano('Jogador Um', 'H-')
    True
    >>> e_humano('Jogador Um', 'HH')
    True
    >>> e_humano('Jogador Dois', 'HH')
    True
    >>> e_humano('Jogador Um', 'HC')
    True
    >>> e_humano('Jogador Dois', 'HC')
    False

    """

    return jogador_atual == JOGADOR_UM or (jogador_atual == JOGADOR_DOIS and tipo_jogo == HUMANO_HUMANO)


# Esta é uma função auxiliar deixada como exemplo.
def esta_metade_revelada(visao: str) -> bool:
    """ Retorna True se e somente se ao menos metade dos caracteres do
        alfabeto em visao foram revelados.

    >>> esta_metade_revelada('')
    True
    >>> esta_metade_revelada('x')
    True
    >>> esta_metade_revelada('^')
    False
    >>> esta_metade_revelada('a^,^c!')
    True
    >>> esta_metade_revelada('a^b^^e ^c^d^^d')
    False

    """

    num_escondida = visao.count(ESCONDIDA)
    num_alfabetica = 0
    for char in visao:
        if char.isalpha():
            num_alfabetica += 1
    return num_alfabetica >= num_escondida


def e_jogo_de_um_jogador(tipo_jogo: str) -> bool:
    """ Retornar True se e somente se este for um jogo para um jogador.

    >>> e_jogo_de_um_jogador('H-')
    True
    >>> e_jogo_de_um_jogador('HH')
    False
    >>> e_jogo_de_um_jogador('HC')
    True

    """
    return tipo_jogo == JOGADOR_UM or tipo_jogo != HUMANO_HUMANO or tipo_jogo == HUMANO_COMPUTADOR


def pontuacao_jogador_atual(pontuacao_jogador_um: int, pontuacao_jogador_dois: int, jogador_atual: str) -> int:
    """ Retornar a pontuação do jogador atual

    >>> pontuacao_jogador_atual(1, 0, JOGADOR_UM)
    1
    >>> pontuacao_jogador_atual(0, 1, JOGADOR_DOIS)
    1
    """
    if jogador_atual == JOGADOR_UM:
        return pontuacao_jogador_um
    else:
        return pontuacao_jogador_dois


def e_letra_bonus(letra: str, quebra_cabeca: str, visao: str) -> bool:
    """ Retornar True se e somente se o primeiro argumento for uma letra bônus.
        Lembre-se de que as letras bônus são consoantes que estão ocultas no momento.

    >>> e_letra_bonus('a', 'banana', 'banana')
    True
    >>> e_letra_bonus('b', 'banana', 'banana')
    False
    >>> e_letra_bonus('n', 'banana', 'banana')
    False
    """
    return letra == 'a' and quebra_cabeca == visao


def atualizar_visao_caractere(quebra_cabeca: str, visao: str, indice: int, palpite: str) -> str:
    """ Retorna o que a visão atualizada do caractere deve ser:
            se o palpite estiver correto, o caractere deve ser revelado;
            caso o contrário a visualização não deve ser alterada.

    >>> atualizar_visao_caractere('apple', '^^^le', 0, 'a')
    'a'
    >>> atualizar_visao_caractere('apple', '^^^le', 2, 'e')
    '^'
    >>> atualizar_visao_caractere('apple', '^^^le', 2, 'p')
    'p'
    """
    if palpite == quebra_cabeca[indice]:
        return palpite
    else:
        return '^'


def calcula_pontuacao(pontuacao_atual: int, num_ocorrencias: int, movimento_atual: str) -> int:
    """ Retorna a nova pontuação atualizada.
        Lembre-se de que adivinhar uma consoante aumenta a pontuação e o
        aumento depende do número de letras adivinhadas, e que comprar uma vogal
        diminui a pontuação em um valor fixo.

    >>> calcula_pontuacao(0,1,'C')
    1
    >>> calcula_pontuacao(0,1,'V')
    0
    >>> calcula_pontuacao(5,3,'C')
    8
    >>> calcula_pontuacao(5,1,'V')
    5
    """
    if movimento_atual == CONSOANTE:
        return pontuacao_atual + num_ocorrencias * PONTOS_CONSOANTE
    else:
        return pontuacao_atual + num_ocorrencias - PRECO_VOGAL


def proximo_jogador(jogador_atual: str, num_ocorrencias: int, tipo_jogo: str) -> str:
    """ Deve fazer com que o jogador volte a jogar na próxima jogada - jogador um ou jogador dois.
        Lembre-se de que se o jogador atual adivinhar corretamente uma consoante ou comprar uma vogal, o jogador joga novamente.
        Se o jogador adivinhar incorretamente, o outro jogador joga na próxima jogada.
        Claro, em um jogo de um jogador, o jogador não muda.

    >>> proximo_jogador(JOGADOR_UM, 1, 'H-')
    'Jogador Um'
    >>> proximo_jogador(JOGADOR_UM, 0, 'HH')
    'Jogador Dois'
    >>> proximo_jogador(JOGADOR_DOIS, 1, 'HH')
    'Jogador Dois'
    >>> proximo_jogador(JOGADOR_DOIS, 0, 'HH')
    'Jogador Um'
    >>> proximo_jogador(JOGADOR_UM, 1, 'HC')
    'Jogador Um'
    """
    a = jogador_atual
    b = num_ocorrencias
    c = tipo_jogo
    if (a == JOGADOR_UM and b != 0) or (a == JOGADOR_UM and b == 0 and c == HUMANO) or (
            a == JOGADOR_DOIS and b == 0 and c == HUMANO_HUMANO):
        return JOGADOR_UM
    return JOGADOR_DOIS


def e_escondida(indice: int, quebra_cabeca: str, visao: str) -> bool:
    """ Retornar True se e somente se o caractere no índice fornecido estiver oculto no jogo.

    >>> e_escondida(0, 'apple', '^^^le')
    True
    >>> e_escondida(1, 'apple', '^^^le')
    True
    >>> e_escondida(0, 'apple', 'a^^le')
    False
    """
    if visao[indice] != quebra_cabeca[indice]:
        return True
    else:
        return False


def computador_escolhe_resolver(visao: str, jogo_atual: str, consoantes: str) -> bool:
    """ Retornar True se e somente se o computador decidir resolver o quebra-cabeça.
        Você pode presumir que essa função só é chamada em um jogo de computador humano.
        A estratégia que usaremos para o computador é a seguinte: Se a dificuldade for difícil,
        o computador decide resolver se pelo menos metade das letras foram reveladas ou se não há mais consoantes para adivinhar.
        Caso contrário, o computador não resolverá.
        Fornecemos uma função auxiliar esta_metade_revelada que você pode usar nesta função.

    >>> computador_escolhe_resolver('^^^le', 'E', 'p')
    False
    >>> computador_escolhe_resolver('^anana', 'E', 'b')
    False
    >>> computador_escolhe_resolver('a^^le', 'H', 'p')
    True
    >>> computador_escolhe_resolver('^^^le', 'H', 'p')
    False
    >>> computador_escolhe_resolver('^a^a^a', 'H', 'b')
    True
    """
    if jogo_atual == DIFICIL and esta_metade_revelada(visao) or consoantes == ' ':
        return True
    else:
        return False


def apague(seq_letras: str, indice: int) -> str:
    """ Retornar as letras fornecidas com o caractere no índice fornecido removido,
        se o índice for um índice válido para aquela sequência de letras.
        Caso contrário, ela deve retornar a seqüência original de letras inalterada.

    >>> apague('banana', 0)
    '^anana'
    >>> apague('melancia', 1)
    'm^lancia'
    >>> apague('apple', 4)
    'appl^'
    >>> apague('apple', 5)
    'apple'
    """
    if indice < len(seq_letras):
        aux = list(seq_letras)
        aux[indice] = ESCONDIDA
        seq_letras = ''.join(aux)
        return seq_letras
    else:
        return seq_letras


if __name__ == '__main__':
    import doctest

    doctest.testmod()
