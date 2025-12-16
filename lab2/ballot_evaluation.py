p, tests = map(int, input().split())

dados = {}

for _ in range(p):
    entrada = input().split()
    nome = entrada[0]
    porcentagem = int(entrada[1].replace(".", ""))
    dados[nome] = porcentagem


for t in range(tests):
    soma = 0
    teste = input()
    if "+" in teste:
        teste = teste.split(" + ")
        ultimo = teste[-1]
        unico = False
        quantidade = len(teste)
    else:
        ultimo = teste
        quantidade = 1
    #quantidade = len(teste)

    if ">=" in ultimo:
        [nome, valor] = ultimo.split(" >= ")
        for i in range(quantidade-1):
            soma += dados[teste[i]]
        soma += dados[nome]
        if soma >= int(valor)*10:
            print(f"Guess #{t+1} was correct.")
        else:
            print(f"Guess #{t+1} was incorrect.")

    elif "<=" in ultimo:
        [nome, valor] = ultimo.split(" <= ")
        for i in range(quantidade-1):
            soma += dados[teste[i]]
        soma += dados[nome]
        if soma <= int(valor)*10:
            print(f"Guess #{t+1} was correct.")
        else:
            print(f"Guess #{t+1} was incorrect.")

    elif ">" in ultimo:
        [nome, valor] = ultimo.split(" > ")
        for i in range(quantidade-1):
            soma += dados[teste[i]]
        soma += dados[nome]
        if soma > int(valor)*10:
            print(f"Guess #{t+1} was correct.")
        else:
            print(f"Guess #{t+1} was incorrect.")

    elif "<" in ultimo:
        [nome, valor] = ultimo.split(" < ")
        for i in range(quantidade-1):
            soma += dados[teste[i]]
        soma += dados[nome]
        if soma < int(valor)*10:
            print(f"Guess #{t+1} was correct.")
        else:
            print(f"Guess #{t+1} was incorrect.")

    elif "=" in ultimo:
        [nome, valor] = ultimo.split(" = ")
        for i in range(quantidade-1):
            soma += dados[teste[i]]
        soma += dados[nome]
        if soma == int(valor)*10:
            print(f"Guess #{t+1} was correct.")
        else:
            print(f"Guess #{t+1} was incorrect.")
    