#include <iostream>
#include <utility> // Para std::swap

// Función auxiliar para imprimir el arreglo
void mostrarArreglo(const int numeros[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << numeros[i] << " ";
    }
    std::cout << std::endl;
}

// Función de ordenamiento por burbuja con métricas de comparación e intercambio
void burbujaConMetricas(int numeros[], int n, int &comparaciones, int &intercambios) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparaciones++; // Se realiza una comparación en cada iteración del bucle interno
            
            if (numeros[j] > numeros[j + 1]) {
                std::swap(numeros[j], numeros[j + 1]);
                intercambios++; // Se incrementa solo cuando se efectúa un intercambio
            }
        }
        
        // Muestra el estado del arreglo en la pasada actual
        std::cout << "Pasada " << (i + 1) << ": ";
        mostrarArreglo(numeros, n);
    }
}

int main() {
    int numeros[] = {7, 6, 5, 4, 3, 2, 1}; // Ejemplo de caso peor (arreglo invertido)
    int n = sizeof(numeros) / sizeof(numeros[0]);

    int comparaciones = 0;
    int intercambios = 0;

    std::cout << "Arreglo original: ";
    mostrarArreglo(numeros, n);
    std::cout << std::endl;

    // Se ejecutan el ordenamiento y el conteo
    burbujaConMetricas(numeros, n, comparaciones, intercambios);

    // Muestra del resumen de métricas
    std::cout << "\nElementos: " << n << std::endl;
    std::cout << "Comparaciones: " << comparaciones << std::endl;
    std::cout << "Intercambios: " << intercambios << std::endl;

    return 0;
}