
nao_bissexto = {
    "January": 31,
    "February": 28,
    "March": 31,
    "April": 30,
    "May": 31,
    "June": 30,
    "July": 31,
    "August": 31,
    "September": 30,
    "October": 31,
    "November": 30,
    "December": 31
}

bissexto = {
    "January": 31,
    "February": 29,
    "March": 31,
    "April": 30,
    "May": 31,
    "June": 30,
    "July": 31,
    "August": 31,
    "September": 30,
    "October": 31,
    "November": 30,
    "December": 31
}

def eh_bissexto(ano):
    if (ano % 100 == 0 and ano % 400 == 0) or (ano % 100 != 0 and ano % 4 == 0):
        return True
    return False

indices_meses = list(nao_bissexto.keys())
casos = int(input())

for i in range(casos):
    data = input().split("-")
    dias = int(input())

    ano = int(data[0])
    mes = data[1]
    dd = int(data[2])
    
    while dias > 0:
        if eh_bissexto(ano):
            dias_no_mes = bissexto[mes]
        else:
            dias_no_mes = nao_bissexto[mes]

        restante = dias_no_mes - dd

        if dias > restante:
            dias -= (restante + 1)
            dd = 1
            indice = indices_meses.index(mes)
            if indice == 11: # se mes 12
                mes = "January"
                ano += 1
            else:
                mes = indices_meses[indice+1]
        else:
            dd += dias
            dias = 0

    print(f"Case {i+1}: {ano}-{mes}-{dd:02d}")
