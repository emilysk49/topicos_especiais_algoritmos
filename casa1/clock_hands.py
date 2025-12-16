graus = []

while True:
    hora, minuto = map(int, input().split(":"))
    if hora == 0 and minuto == 0:
        break
    # 360/12 = 30 grau por hora
    # 30/60 = 0.5 grau por minito 
    grau_hora = (hora*30)+(minuto*0.5)
    # 360/60 = 6 grau por minuto
    grau_minuto = minuto*6

    grau = abs(grau_hora-grau_minuto)
    
    if grau > 180:
        grau = 360 - grau

    graus.append(f"{grau:.3f}")

print("\n".join(graus))



    



