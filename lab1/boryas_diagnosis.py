n = int(input())

dias = 0

for i in range(n):
    s, d = map(int, input().split())
    if i == 0:
        dias += s
    elif dias < s: #chega depois 
        dias = s
    elif dias >= s: #ja chegou
        prox = s
        while dias > prox + (d * 100):
            prox += d * 100
        while dias > prox + (d * 10):
            prox += d * 10
        while prox <= dias:
            prox += d
        dias = prox

print(dias)
