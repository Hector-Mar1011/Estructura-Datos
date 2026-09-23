# Planteamiento del problema.
"""
Las calificaciones  de tres alumnos son:
"""
alumno1 = [80, 90, 85]
alumno2 = [70, 75, 72]
alumno3 = [95, 88, 92]

Lc = [alumno1, alumno2, alumno3]

for i in range(len(Lc)):
    promedio = sum(Lc[i]) / len(Lc[i])
    print(f"El promedio del alumno es: {promedio}")


