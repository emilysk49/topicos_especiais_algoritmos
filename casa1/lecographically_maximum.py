n = int(input())
lista = list(map(int, input().split()))

bits = [0] * 30

for num in lista:
    for b in range(30):
        if num & (1 << b):
            bits[b] += 1

res = [0] * n
for b in range(29, -1, -1):  # bits mais altos primeiro
    for i in range(bits[b]):
        res[i] |= (1 << b)

print(*res)