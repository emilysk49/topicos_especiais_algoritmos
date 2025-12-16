n = int(input())
lista = []

for _ in range(n):
    entrada = input()

    if entrada == "Kick":
        if lista != []:
            lista.pop()
    elif entrada == "Test":
        if lista != []:
            nome = lista[-1]
            print(nome)
        else:
            print("Not in a dream")
    else: # sleep X
        [sleep, nome] = entrada.split()
        lista.append(nome)