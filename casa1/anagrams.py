def criar_dict(s):
    d = {}
    for c in s:
        if c != " ":
            # tenta pegar chave c, se nao tem retorna 0
            d[c] = d.get(c, 0) + 1
    return d

caso = int(input())

input()

for t in range(caso):
    palavra = input()
    palavras = [palavra]

    while True:
        try:
            palavra = input()
            if palavra != "" and palavra != " ":
                palavras.append(palavra)
            else: 
                break
        except EOFError:
            break

    quantidade = len(palavras)
    anagramas = []

    for p in range(quantidade): # pega uma palavra
        for i in range(p+1,quantidade): # pega um por um do resto
            p1 = criar_dict(palavras[p])
            p2 = criar_dict(palavras[i])
            if p1 == p2:
                menor, maior = sorted([palavras[p], palavras[i]])
                anagramas.append((menor, maior))
                
    for a in sorted(anagramas):
        p1,p2 = a
        print(f"{p1} = {p2}")

    if t != caso - 1:
        print()