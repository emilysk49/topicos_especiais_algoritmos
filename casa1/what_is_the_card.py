def calcular_ponto(x):
    if x == 'A' or x == 'J' or x == 'Q' or x == 'K' or x == 'T':
        return 10
    else:
        return int(x)


caso = int(input())

for n in range(caso):
    cartas = input().split()

    primeiras_25 = cartas[27:]
    monte = cartas[:27]

    y = 0

    for i in range(3):
        x = monte.pop()
        x = calcular_ponto(x[0])
        y += x
        pegar_cartas = 10 - x
        for c in range(pegar_cartas):
            monte.pop()
        
    indice = y - len(monte)
    valor = primeiras_25[indice-1]
    print(f"Case {n+1}: {valor}")