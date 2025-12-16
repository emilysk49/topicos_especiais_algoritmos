n = int(input())

parado = True
direcao = None
espera = False

paraDireita = []
paraEsquerda = []

tempo_total = 0

for i in range(n):
    t,d = map(int, input().split())
    if d == 0: #se vai para direita
        paraDireita.append(t)
    else: #se vai para esquerda
        paraEsquerda.append(t)

while True:
    if (paraDireita == [] and paraEsquerda != []) or (paraEsquerda == [] and paraDireita != []):
        if paraDireita != []:
            t = max(paraDireita)
        else:
            t = max(paraEsquerda)
        if direcao == None:
            tempo_total += t + 10
        elif t < tempo_total:
            tempo_total += 10
        else:
            tempo_total += (t - tempo_total) + 10
        print(tempo_total)
        break

    elif direcao == None:
        if paraDireita[0] < paraEsquerda[0]:
            t = paraDireita.pop(0)
            tempo_total += t + 10
            direcao = 0
        else:
            t = paraEsquerda.pop(0)
            tempo_total += t + 10
            direcao = 1

    elif direcao == 0:
        if paraDireita[0] <= tempo_total:
            t = paraDireita.pop(0)
            tempo_total += ((t+10)-tempo_total)
            direcao = 0
        else:
            if paraDireita[0] < paraEsquerda[0]:
                t = paraDireita.pop(0)
                tempo_total += ((t - tempo_total) + 10)
                direcao = 0
            else:
                t = paraEsquerda.pop(0)
                if t < tempo_total: #se tava esperando
                    while paraEsquerda != [] and paraEsquerda[0] < tempo_total: #vai removendo os que estavam na fila
                        t = paraEsquerda.pop(0)
                    tempo_total += 10
                else:
                    tempo_total += ((t - tempo_total) + 10)
                direcao = 1
                
    else: #direcao = 1
        if paraEsquerda[0] <= tempo_total:
            t = paraEsquerda.pop(0)
            tempo_total += ((t+10)-tempo_total)
            direcao = 1
        else:
            if paraEsquerda[0] < paraDireita[0]:
                t = paraEsquerda.pop(0)
                tempo_total += ((t - tempo_total) + 10)
                direcao = 1
            else:
                direcao = 0
                t = paraDireita.pop(0)
                if t < tempo_total: #se tava esperando
                    while paraDireita != [] and paraDireita[0] < tempo_total: #vai removendo os que estavam na fila
                        t = paraDireita.pop(0)
                    tempo_total += 10
                else:
                    tempo_total += ((t - tempo_total) + 10)



