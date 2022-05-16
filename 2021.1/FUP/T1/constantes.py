""" Trabalho 1: Constantes do quebra-cabeças de frases"""

# pontos ganhos em cada ocorrência de uma consoante adivinhada corretamente
PONTOS_CONSOANTE = 1

# custo de compra de vogal, não depende do número de ocorrências
PRECO_VOGAL = 1

# pontos ganhos em cada ocorrência de consoantes escondidas
# #no momento de reRESOLVERr o quebra-cabeça
BONUS_CONSOANTE = 2

# nomes dos jogadores
JOGADOR_UM = 'Jogador Um'
JOGADOR_DOIS = 'Jogador Dois'

# opções menu
CONSOANTE = 'C'  # advinhe a CONSOANTE
VOGAL = 'V'      # compre a vogal
RESOLVER = 'R'   # tente resolver o quebra-cabeça
SAIR = 'S'       # sair do jogo

# símbolos usados para caracteres escondidos
ESCONDIDA = '^'

# Game types
HUMANO = 'H-'             # um jogador, HUMANO
HUMANO_HUMANO = 'HH'       # dois jogadores, ambos HUMANO
HUMANO_COMPUTADOR = 'HC'    # dois jogadores, humano e computador

# nível de dificuldade do computador
FACIL = 'E'  # computador joga a estratégia "fácil"
DIFICIL = 'H'  # computador joga a estratégia "difícil"

# todas consoantes e vogais
TODAS_CONSOANTES = 'bcdfghjklmnpqrstvwxyz'
TODAS_VOGAIS = 'aeiou'

# a ordem em que o computador, no nível difícil, irá
# adivinhar consoantes
PRIORIDADE_CONSOANTES = 'tnrslhdcmpfygbwvkqxjz'