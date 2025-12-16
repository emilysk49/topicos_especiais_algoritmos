r, l, d, m, n = map(int, input().split())
total_votos = r + l + d + m + n
votos = [r,l,d,m]
pessoas = ["Rafael", "Leonardo", "Donatello", "Michelangelo"]
vencedores = []

for i in range(4):
    v = (votos[i]+n) / total_votos
    if v > 0.5:
        vencedores.append(pessoas[i])
    
if vencedores == []:
    print("sem vencedores")
else:
    for i in sorted(vencedores):
        print(i)