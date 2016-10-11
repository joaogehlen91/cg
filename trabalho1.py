from operator import itemgetter

matriz = []
for i in range(10):
    linha = []
    for j in range(10):
        linha.append(' ')
    matriz.append(linha)


class Aresta:
    def __init__(self, yIni, yFim, x, dx):
        self.yIni = yIni
        self.yFim = yFim
        self.x = x
        self.dx = dx


#vertices (x, y)
vertices = [(20, 8), (2, 45), (80, 65), (97, 60)]


ymax = 65
ymin = 8

# yini, yfim, x, dx
#pol = v1->v2 v1->v3 v2->v4 v3->v4
arestas = [(8, 45, 2, 0.0), (8, 65, 20, 1.05), (45, 60, 2, 6.34), (60, 65, 80, -3.4)]


LAA = []

for y in range(ymin, ymax):
    print(LAA)
    for i in arestas:
        if i[0] == y:
            LAA.append(i)
    
    for i in LAA:
        if i[1] == y:
            LAA.pop(LAA.index(i))

    LAA.sort(key=itemgetter(2))
    print(LAA)