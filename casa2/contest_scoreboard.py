casos = int(input())

input()

for c in range(casos):
    resultados = {}
    incorretos = {}
    while True:
        try:
            entrada = input()
        except EOFError:
            break

        if entrada == "":
            break

        j, p, t, l = entrada.split()
        j, p, t = map(int, (j, p, t))

        if j not in resultados:
            resultados[j] = {}
            incorretos[j] = {}

        if p not in incorretos[j]:
            incorretos[j][p] = 0

        if l == "C":
            if p not in resultados[j]:
                resultados[j][p] = t + 20 * incorretos[j][p]
        elif l == "I":
            if p not in resultados[j]:
                incorretos[j][p] += 1
        else:
            continue
    
    tabela = []
    for j,ps in resultados.items():
        penalidade = 0
        for p, t in ps.items():
            penalidade += t
        corretos = len(ps)
        tabela.append((j, corretos, penalidade))

    # negativo -x[1] -> mais correto (maior -> menor)
    ordenado = sorted(tabela, key=lambda x: (-x[1], x[2], x[0]))
    for jogador, corretos, penalidade in ordenado:
        print(jogador, corretos, penalidade)

    if c != casos-1:
        print()
