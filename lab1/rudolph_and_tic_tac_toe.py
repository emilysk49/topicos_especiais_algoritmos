n = int(input())

jogo = []
deu = False

for i in range(n):
    for l in range(3):
        linha = input()
        linha = [linha[0], linha[1], linha[2]]
        if len(set(linha)) == 1 and linha[0] != "." and not deu:
            print(linha[0])
            deu = True
        jogo.append(linha)
    if deu:
        deu = False
    elif jogo[0][0] == jogo[1][1] and jogo[1][1] == jogo[2][2] and jogo[0][0] != ".":
        print(jogo[0][0])
    elif jogo[0][2] == jogo[1][1] and jogo[1][1] == jogo[2][0] and jogo[0][2] != ".":
        print(jogo[0][2])
    elif jogo[0][0] == jogo[1][0] and jogo[1][0] == jogo[2][0] and jogo[0][0] != ".":
        print(jogo[0][0])
    elif jogo[0][1] == jogo[1][1] and jogo[1][1] == jogo[2][1] and jogo[0][1] != ".":
        print(jogo[0][1])
    elif jogo[0][2] == jogo[1][2] and jogo[1][2] == jogo[2][2] and jogo[0][2] != ".":
        print(jogo[0][2])
    else:
        print("DRAW")
    jogo.clear()