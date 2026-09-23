#include <iostream>

// Función recursiva para calcular el n-ésimo término de Fibonacci
long long fibonacci(int n) {
    if (n <= 0) return 0; // Caso base 1
    if (n == 1) return 1; // Caso base 2
    
    return fibonacci(n - 1) + fibonacci(n - 2); // Llamada recursiva
}

int main() {
    int n;

    std::cout << "Ingrese el valor de n para calcular la serie de Fibonacci: ";
    std::cin >> n;

    if (n < 0) {
        std::cout << "Por favor, ingrese un numero entero mayor o igual a 0." << std::endl;
        return 1;
    }

    // Bucle para imprimir la secuencia desde 0 hasta n
    for (int i = 0; i <= n; ++i) {
        std::cout << "Fibonacci(" << i << ") = " << fibonacci(i) << std::endl;
    }

    return 0;
}