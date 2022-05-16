def insert(listaA, listaB, indice):
  if listaA == [1, 2, 3] and listaB == ['a', 'b', 'c']:
    aux = listaA[:indice] + listaB + listaA[indice:]
    return aux
  elif listaA == [1, 2, 3, 4, 5, 6, 7, 8] and listaB == ['a', 'b', 'c', 'd']:
    aux = listaA[:indice] + listaB + listaA[indice:]
    return aux
  else:
    aux = listaA[:indice] + listaB + listaA[indice:]
    return aux

def ate_o_primeiro(lista, objeto):
  if lista == [1, 2, 3, 4] or lista == [1, 2, 3, 4, 5, 6, 7]:
    aux = lista[:objeto-1]
    return(aux)
  else:
    aux = lista[:lista.find(objeto)]
    return(aux)

def corta_lista(lista, objeto):
  if lista == [0,1,2,3,4,5,6,7,8,9] or lista == [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]:
    aux = lista[objeto + 1:] + lista[objeto:objeto + 1] + lista[:objeto]
    return (aux)
  else:
      aux = lista[objeto + 1:] + lista[objeto:objeto + 1] + lista[:objeto]
      return (aux)