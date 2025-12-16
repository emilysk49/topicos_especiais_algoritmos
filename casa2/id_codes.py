code = input()

while code != '#':
    code = list(code)
    # maior i : code[i] < code[i+1]
    # ex: abaacb 
    i = len(code) - 2 # i = 6 - 2 = 4
    # code[4](c) >= code[5](b) -> True
    # code[3](a) >= code[4](c) -> False (i=3)
    while i >= 0 and code[i] >= code[i+1]:
        i -= 1

    if i == -1: # ultima permutacao
        print("No Successor")
        code = input()
        continue
    
    # maior j : code[j] > code[i]
    j = len(code) - 1 # j = 4 - 1 = 5
    # code[5](b) <= code[3](a) -> False (j=5)
    while code[j] <= code[i]:
        j -= 1

    # troca code[3](a) = code[5](b) e code[5](b) = code[3](a)
    code[i], code[j] = code[j], code[i]

    # ababca
    # code[3+1:] -> abab "ca" -> reverse("ca") -> abab ac
    code[i+1:] = reversed(code[i+1:])
    print("".join(code))
    code = input()
    