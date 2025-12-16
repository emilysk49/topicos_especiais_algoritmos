from bisect import insort

casos = int(input())

for _ in range(casos):
    n = int(input())
    cartas = list(map(int, input().split()))

    bonus = []
    resultado = 0

    for c in cartas:
        if c == 0 and bonus != []:
            maior = bonus.pop()
            resultado += maior
        elif c > 0:
            insort(bonus, c)
        
    print(resultado)