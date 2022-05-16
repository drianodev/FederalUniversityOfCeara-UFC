from modulo import *


if __name__ == '__main__':
    print('Questão 1\n')
    print("TESTE -> [1, 2, 3], ['a', 'b', 'c'], 2")
    print(insert([1, 2, 3], ['a', 'b', 'c'], 2))

    print("\nTESTE -> [1, 2, 3, 4, 5, 6, 7, 8], ['a', 'b', 'c', 'd'], 3")
    print(insert([1, 2, 3, 4, 5, 6, 7, 8], ['a', 'b', 'c', 'd'], 3))

    print('\nTESTE -> "123","abc",2')
    print(insert("123","abc",2))

    print('\nQuestão 2\n')
    print('\nTESTE -> [1, 2, 3, 4], 3')
    print(ate_o_primeiro([1, 2, 3, 4], 3))

    print('\nTESTE -> [1, 2, 3, 4], 9')
    print(ate_o_primeiro([1, 2, 3, 4], 9))

    print('\nTESTE -> [1, 2, 3, 4, 5, 6, 7], 4')
    print(ate_o_primeiro([1, 2, 3, 4, 5, 6, 7], 4))

    print("\nTESTE -> 'abcdef', 'd'")
    print(ate_o_primeiro('abcdef', 'd'))

    print('\nQuestão 3\n')
    print('TESTE -> [0,1,2,3,4,5,6,7,8,9], 3')
    print(corta_lista([0,1,2,3,4,5,6,7,8,9], 3))

    print('\nTESTE -> [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15], 8')
    print(corta_lista([0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15], 8))

    print('\nTESTE -> "ABCDEFGX1234",7')
    print(corta_lista("ABCDEFGX1234",7))
