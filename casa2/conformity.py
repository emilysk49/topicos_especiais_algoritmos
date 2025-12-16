while True:
    calouros = int(input())
    if calouros == 0:
        break

    combinacoes = {}
    count = 0

    for _ in range(calouros):
        cursos = list(map(int, input().split()))
        cursos.sort()
        chave = tuple(cursos)
        if chave in combinacoes:
            combinacoes[chave] += 1
        else:
            combinacoes[chave] = 1

    max_popular = max(combinacoes.values())
    for n in combinacoes.values():
        if n == max_popular:
            count += n

    print(count)