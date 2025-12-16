import bisect

count = 1
n = int(input())

while n != 0:
    conjuntosN = []
    somas = []

    for i in range(n):
        num = int(input())
        if i != 0:
            for c in conjuntosN:
                somas.append(num+c)
        conjuntosN.append(num)

    somas = sorted(somas)

    m = int(input())
    print(f"Case {count}:")

    for _ in range(m):
        num = int(input())
        posicao = bisect.bisect_left(somas, num)
        if posicao == 0:
            print(f"Closest sum to {num} is {somas[0]}.")
            continue
        elif posicao == len(somas):
            print(f"Closest sum to {num} is {somas[-1]}.")
            continue

        anterior = somas[posicao-1]
        posterior = somas[posicao]

        if abs(num - anterior) <= abs(num - posterior):
            print(f"Closest sum to {num} is {anterior}.")
        else:
            print(f"Closest sum to {num} is {posterior}.")

    count += 1
    n = int(input())


