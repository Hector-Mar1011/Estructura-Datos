#include <iostream>
#include <vector>

void imprimirArreglo(const std::vector<int>& arr) {
    for (size_t k = 0; k < arr.size(); ++k) {
        std::cout << arr[k] << (k == arr.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;
}

void ordenamientoSeleccion(std::vector<int>& arr) {
    size_t n = arr.size();
    int comparaciones = 0;
    int intercambios = 0;
    
    for (size_t i = 0; i < n - 1; ++i) {
        size_t min_idx = i;
        
        for (size_t j = i + 1; j < n; ++j) {
            comparaciones++; // Se realiza una comparación entre elementos
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        
        // Intercambio de valores
        if (min_idx != i) {
            std::swap(arr[i], arr[min_idx]);
            intercambios++; // Se incrementa al realizar la permuta de elementos
        }
        
        // Imprimir el estado del arreglo al finalizar la pasada
        std::cout << "Pasada " << (i + 1) << ":" << std::endl;
        imprimirArreglo(arr);
    }

    // Mostrar el resumen de métricas al finalizar el ordenamiento
    std::cout << "\nComparaciones hechas: " << comparaciones << std::endl;
    std::cout << "Intercambios hechos: " << intercambios << std::endl;
}

int main() {
    std::vector<int> datos = {621, 84, 937, 315, 476, 152, 803, 27, 694, 548,
 371, 916, 203, 765, 439, 58, 827, 286, 603, 119,
 972, 341, 714, 65, 529, 881, 247, 398, 756, 173,
 634, 22, 845, 462, 709, 134, 953, 317, 581, 96,
 428, 773, 251, 607, 862, 44, 695, 328, 517, 789,
 186, 934, 73, 556, 402, 918, 145, 671, 263, 849,
 36, 725, 491, 608, 157, 883, 294, 532, 761, 113,
 647, 354, 905, 218, 779, 61, 583, 427, 996, 324,
 716, 189, 875, 47, 638, 267, 540, 812, 98, 453,
 729, 174, 590, 335, 941, 126, 684, 256, 817, 369}; // Arreglo de prueba
    
    ordenamientoSeleccion(datos);
    
    return 0;
}