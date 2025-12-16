from bisect import insort
numeros = []

while True:
    try:
        n = input()
        if n != "":
            insort(numeros, int(n))
            if len(numeros) == 0:
                mediano = numeros[0]
            elif len(numeros) % 2 == 0:
                metade = len(numeros) // 2
                soma = numeros[metade-1] + numeros[metade] 
                mediano = soma // 2
            else:
                metade = len(numeros) // 2
                mediano = numeros[metade]
            print(mediano)
        else:
            break
    except EOFError:
        break

