#include <iostream>

using namespace std;

int main() {
    int tamano;


    // 1. Solicitar el tamaño del arreglo
    cout << "Ingrese el tamano del arreglo: ";
    cin >> tamano;

    // Validación del tamaño ingresado
    if (tamano <= 0) {
        cout << "El tamano debe ser un numero mayor a 0." << endl;
        return 1;
    }

    // Crear el arreglo en memoria dinámica usando punteros tradicionales
    int* arreglo = new int[tamano];

    // 2. Capturar los elementos desde el teclado
    cout << "\n--- Captura de elementos ---" << endl;
    for (int i = 0; i < tamano; i++) {
        cout << "Ingrese el elemento [" << i << "]: ";
        cin >> arreglo[i];
    }

    // 3. Mostrar todos los elementos del arreglo
    cout << "\n--- Elementos del arreglo ---" << endl;
    for (int i = 0; i < tamano; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;

    // 4. Calcular Suma, Promedio, Mayor y Menor
    int suma = 0;
    int mayor = arreglo[0];
    int menor = arreglo[0];

    for (int i = 0; i < tamano; i++) {
        suma += arreglo[i];

        if (arreglo[i] > mayor) {
            mayor = arreglo[i];
        }
        if (arreglo[i] < menor) {
            menor = arreglo[i];
        }
    }

    double promedio = static_cast<double>(suma) / tamano;

    // Mostrar cálculos
    cout << "\n--- Resultados Estadisticos ---" << endl;
    cout << "Suma total: " << suma << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Valor mayor: " << mayor << endl;
    cout << "Valor menor: " << menor << endl;

    // 5. Permitir buscar un número dentro del arreglo
    int numeroBuscar;
    cout << "\n--- Busqueda de un numero ---" << endl;
    cout << "Ingrese el numero que desea buscar: ";
    cin >> numeroBuscar;

    bool encontrado = false;
    for (int i = 0; i < tamano; i++) {
        if (arreglo[i] == numeroBuscar) {
            cout << "El numero " << numeroBuscar << " fue encontrado en la posicion (indice): " << i << endl;
            encontrado = true;
            break; // Detiene la búsqueda al encontrar la primera coincidencia
        }
    }

    if (!encontrado) {
        cout << "El numero " << numeroBuscar << " no se encuentra en el arreglo." << endl;
    }

    // 6. Mostrar los elementos en orden inverso
    cout << "\n--- Elementos en orden inverso ---" << endl;
    for (int i = tamano - 1; i >= 0; i--) {
        cout << arreglo[i] << " ";
    }
    cout << endl;

    // Liberar la memoria dinámica asignada
    delete[] arreglo;

    return 0;
}