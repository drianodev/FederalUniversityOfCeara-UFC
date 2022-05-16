def categoria_tempestade(velocidade):
    '''(int) -> int 
    Returna a categoria ao qual o vento pertence.
    >>> categoria_tempestade(90)
    0
    >>> categoria_tempestade(130)
    1
    >>> categoria_tempestade(165)
    2
    >>> categoria_tempestade(190)
    3
    >>> categoria_tempestade(220)
    4
    >>> categoria_tempestade(260)
    5
    '''

def mensagem_categoria(categoria):
    '''(int) -> str 
    Retorna uma mensagem de aviso relacionada a categoria de tempestade.  
    
    Requisito: 0 <= categoria <= 5
	
    >>> mensagem_categoria(0)
    'Não é uma grande ameaça.'
    >>> mensagem_categoria(1)
    'Ventos muito perigosos causarão alguns danos.'
    >>> mensagem_categoria(2)
    'Ventos extremamente perigosos causarão danos extensos.'
    >>> mensagem_categoria(3)
    'Danos devastadores ocorrerão.'
    >>> mensagem_categoria(4)
    'Danos catastróficos ocorrerão.'
    >>> mensagem_categoria(5)
    'Ocorrerão danos cataclísmicos.'
    '''
    
def aviso(speed):
    '''(int) -> str
    Dada a velocidade do vento de tempestade, retorne a mensagem de aviso associada.
    >>> aviso(90)
    'Não é uma grande ameaça.'
    >>> aviso(130)
    'Ventos muito perigosos causarão alguns danos.'
    >>> aviso(165)
    'Ventos extremamente perigosos causarão danos extensos.'
    >>> aviso(199)
    'Danos devastadores ocorrerão.'
    >>> aviso(225)
    'Danos catastróficos ocorrerão.'
    >>> aviso(280)
    'Ocorrerão danos cataclísmicos.'
    '''
    
if __name__ == '__main__':
    pass
