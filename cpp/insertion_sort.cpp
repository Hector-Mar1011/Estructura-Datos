#include <iostream>
using namespace std;

// Función para imprimir los elementos del arreglo
void mostrarArreglo(int numeros[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << numeros[i] << " ";
    }
    cout << endl;
}

// Función que implementa el ordenamiento por inserción y registra métricas
void ordenamientoInsercion(int numeros[], int n)
{
    int comparaciones = 0;
    int desplazamientos = 0;
    int inserciones = 0;

    for (int i = 1; i < n; i++)
    {
        int clave = numeros[i];
        int j = i - 1;

        cout << "\nInsertando: " << clave << endl;

        // Compara desplaza los elementos mayores hacia la derecha
        while (j >= 0)
        {
            comparaciones++;
            if (numeros[j] > clave)
            {
                numeros[j + 1] = numeros[j];
                desplazamientos++;
                j--;
            }
            else
            {
                break; // Se encontró la posición correcta
            }
        }

        numeros[j + 1] = clave;
        inserciones++;

        // Muestra el estado del arreglo tras la inserción
        mostrarArreglo(numeros, n);
    }

    // Impresión de estadísticas generales
    cout << "\n========================================" << endl;
    cout << "       ESTADISTICAS" << endl;
    cout << "========================================" << endl;
    cout << "Comparaciones:   " << comparaciones << endl;
    cout << "Desplazamientos: " << desplazamientos << endl;
    cout << "Inserciones:     " << inserciones << endl;
}

int main()
{
    int numeros[] = {7, 3, 8, 2, 6, 4, 5};
    int n = 7;

    cout << "Arreglo original:" << endl;
    mostrarArreglo(numeros, n);

    ordenamientoInsercion(numeros, n);

    return 0;
}