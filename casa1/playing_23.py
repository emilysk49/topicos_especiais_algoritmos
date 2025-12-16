n = int(input())

cartasJ = list(map(int, input().split()))
cartasM = list(map(int, input().split()))
cartas_comuns = list(map(int, input().split()))

cartas_contador = [0] * 13

def contar_ponto(carta):
    if carta >= 10:
        return 10
    return carta

cartas_contador[cartasJ[0]-1] += 1
cartas_contador[cartasJ[1]-1] += 1
cartas_contador[cartasM[0]-1] += 1
cartas_contador[cartasM[1]-1] += 1

somaJ = 0
somaM = 0
for i in cartas_comuns:
    cartas_contador[i-1] += 1
    somaJ += contar_ponto(i)
    somaM += contar_ponto(i)

somaJ += (contar_ponto(cartasJ[0]) + contar_ponto(cartasJ[1]))
somaM += (contar_ponto(cartasM[0]) + contar_ponto(cartasM[1]))

nao_existe = False
if somaM >= 23:
    print("-1")
elif somaJ >= 23:
    print("-1")
elif somaJ > somaM: #estourar do John
    valor_carta = 24 - somaJ
    limite = 24 - somaM
    if valor_carta > 10:
        print("-1")
        nao_existe = True
    while (not nao_existe) and cartas_contador[valor_carta-1] == 4:
        valor_carta += 1
        if (valor_carta == 13 and cartas_contador[-1] == 4) or (contar_ponto(valor_carta) == limite):
            print("-1")
            nao_existe = True
            break
    if not nao_existe:
        print(valor_carta)
elif somaJ <= somaM: #chegar no 23 da Mary
    valor_carta = 23 - somaM
    if valor_carta > 10 or cartas_contador[valor_carta-1] == 4:
        print("-1")
    else:
        print(valor_carta)