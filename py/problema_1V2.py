# Planteamiento del problema.
"""
Las calificaciones  de tres alumnos son:
"""
alumno1 = [80, 90, 85]
alumno2 = [70, 75, 72]
alumno3 = [95, 88, 92]

Lc = [alumno1, alumno2, alumno3]    
"""
Ahora haremos lo mismo pero utilizando las variables total = 0 (Para almacenar la suma)
y contador = 0 (Para almacenar el número de calificaciones)
"""
for i in range(len(Lc)):
    total = 0
    contador = 0
    for j in range(len(Lc[i])):
        total += Lc[i][j]
        contador += 1

    promedio = total / contador
    print(f"El promedio del alumno {i+1} es:", round(promedio, 2))
