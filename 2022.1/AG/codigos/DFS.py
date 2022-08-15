from lista import loadlista

def DFS_VISIT(u):
    global mark
    cor[u] = "CINZA"
    mark = mark + 1
    d[u] = mark
    for v in lista_adj[u]:
        if cor[v] == "BRANCO":
            DFS_VISIT(v)
    cor[u] = "PRETO"
    mark = mark +1
    f[u] = mark

def DFS():
    for u in V:
        cor[u] = "BRANCO"
    mark = 0
    for u in V:
        if cor[u] == "BRANCO":
            DFS_VISIT(u)


[lista_adj, N] = loadlista()
V = [0,1,2,3,4,5,6,7]
mark = 0
cor = ["VERMELHO"]*N
d = [0]*N
f = [0]*N
DFS()
print(d,f)
