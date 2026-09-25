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
    
    for (size_t i = 0; i < n - 1; ++i) {
        size_t min_idx = i;
        
        for (size_t j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        
        // Intercambio de valores
        if (min_idx != i) {
            std::swap(arr[i], arr[min_idx]);
        }
        
        // Imprimir el estado del arreglo al finalizar la pasada
        std::cout << "Pasada " << (i + 1) << ":" << std::endl;
        imprimirArreglo(arr);
    }
}

int main() {
    std::vector<int> datos = {64, 25, 12, 22, 11}; // Puedes sustituir por tus datos de prueba
    
    ordenamientoSeleccion(datos);
    
    return 0;
}


