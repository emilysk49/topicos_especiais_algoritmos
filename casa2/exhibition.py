casos = int(input())

for c in range(casos):
    amigos = int(input())
    selos_unicos = set()
    selos = []
    result = []

    for _ in range(amigos):
        lista = list(map(int,input().split()))
        selos.append(lista[1:])

    selo_map = {}
    for i, s in enumerate(selos):
        for selo in s:
            if selo not in selo_map:
                selo_map[selo] = set()
            selo_map[selo].add(i)
    
    unicos = [0] * amigos

    for selo, donos in selo_map.items():
        if len(donos) == 1:
            dono = list(donos)[0]
            unicos[dono] += 1

    total = sum(unicos)

    print(f"Case {c+1}: ", end="")
    for n in range(amigos):
        if n == amigos - 1:
            print(f"{(unicos[n]/total)*100:.6f}%")
        elif unicos[n] == 0:
            print("0.000000%", end=" ")
        else:
            print(f"{(unicos[n]/total)*100:.6f}%", end=" ")
    
