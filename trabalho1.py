matriz = []
for i in xrange(10):
    linha = []
    for j in xrange(10):
        linha.append(' ')
    matriz.append(linha)


class Aresta:
    def __init__(self, yIni, yFim, x, dx):
        self.yIni = yIni
        self.yFim = yFim
        self.x = x
        self.dx = dx



vetores = [(20, 8), (2, 45), (80, 65), (97, 60)]
#pol = v1->v2 v1->v3 v2->v4 v3->v4

ymax = 65
ymin = 8

# yini, yfim, x, dx
arestas = [(8, 45, 20, 0), (8, 65, 20, 0), (45, 65, 2, 0), (65, 60, 80, 0)]

LAA = [(8, 45, 20, 0), (8, 45, 20, 0), (45, 65, 2, 0), (65, 60, 80, 0)]

