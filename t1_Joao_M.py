# Autor: Joao Miguel
# Disciplina: Computacao Grafica


from operator import itemgetter

matriz = []
for i in range(60):
    linha = []
    for j in range(60):
        linha.append('-')
    matriz.append(linha)


def imprimeMatriz(matriz):
    for i in matriz:
        for j in i:
            print(j, " ", end="")
        print()    


class Aresta:
    def __init__(self, yIni, yFim, x, dx):
        self.yIni = yIni
        self.yFim = yFim
        self.x = x
        self.dx = dx
    
    def __repr__(self):
        return "("+str(self.yIni) + ", "+str(self.yFim) +", "+  str(self.x)+", " +str(self.dx)+")"



#vertices (x, y)
#vertices = [(20, 8), (2, 45), (80, 65), (97, 60)]
#vertices = [(10, 4), (2, 28), (30, 42), (45, 20)]
vertices = [(10, 4), (1, 22), (48, 30), (40, 32)]



y = vertices[:]
y.sort(key=itemgetter(1), reverse=True)
ymax = y[0][1]
y.sort(key=itemgetter(1))
ymin = y[0][1]


arestas = []

# gera lista de arestas
for i in range(len(vertices)):
    vi = i
    vf = 0 if (i == len(vertices) - 1) else i+1
    yini = min(vertices[vi][1], vertices[vf][1])
    yfim = max(vertices[vi][1], vertices[vf][1])
    #x = min(vertices[vi][0], vertices[vf][0])
    aux = [vertices[vi], vertices[vf]]
    aux.sort(key = itemgetter(1))
    x = aux[0][0]
    #x = vertices[vf][0]
    dx = round((vertices[vf][0] - vertices[vi][0]) / ((vertices[vf][1] - vertices[vi][1])), 2)
    a = Aresta(yini, yfim, x, dx)
    arestas.append(a)


#Ordena por Y Inicial
arestas.sort(key = lambda x:(x.yIni))


LAA = []

# for y = ymin to ymax do
for y in range(ymin, ymax):
    
    for i in arestas:
        if i.yIni == y:
            LAA.append(i)
    
    for i in LAA:
        if i.yFim == y:
            LAA.pop(LAA.index(i))


    LAA.sort(key= lambda x: x.x)
    

    #foreach (a1, a2) E LAA | a2 segue a1 do
    for i in range(len(LAA)-1):
        for x in range(round(LAA[i].x), round(LAA[i+1].x)):
            matriz[y][x] = '#'

    for i in LAA:
        i.x = i.x + i.dx

imprimeMatriz(matriz)
