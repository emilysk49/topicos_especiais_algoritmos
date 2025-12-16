n = int(input())
saida = []

for i in range(n):
    c, d = map(int, input().split())
    f = (9*c)/5 + 32
    aumento = f + d
    conversao = (aumento-32)*(5/9)
    saida.append(f"Case {i+1}: {conversao:.2f}")

print("\n".join(saida))