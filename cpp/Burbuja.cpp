#include <iostream>
#include <utility> // Para std::swap

void burbuja(int numeros[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool huboIntercambio = false; // Variable para optimizar el algoritmo

        for (int j = 0; j < n - i - 1; j++) {
            // Comparación de elementos adyacentes
            if (numeros[j] > numeros[j + 1]) {
                // Intercambio de valores
                std::swap(numeros[j], numeros[j + 1]);
                huboIntercambio = true;
            }
        }

        // Si no hubo ningún intercambio en esta pasada, el arreglo ya está ordenado
        if (!huboIntercambio) {
            break;
        }
    }
}

int main() {
    int arreglo[] = {5, 2, 8, 1, 9, 4};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);

    std::cout << "Arreglo original: ";
    for (int i = 0; i < n; i++) {
        std::cout << arreglo[i] << " ";
    }
    std::cout << std::endl;

    // Llamada a la función
    burbuja(arreglo, n);

    std::cout << "Arreglo ordenado: ";
    for (int i = 0; i < n; i++) {
        std::cout << arreglo[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}