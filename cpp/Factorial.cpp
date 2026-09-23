#include <iostream>

// Función recursiva que calcula el factorial e imprime la traza de ejecución
long long factorial(int n) {
    // Imprime la llamada actual (fase de apilado)
    std::cout << "Calculando factorial(" << n << ")" << std::endl;

    // Caso base
    if (n <= 0) {
        std::cout << "factorial(0) = 1" << std::endl;
        return 1;
    }

    // Llamada recursiva
    long long resultadoAnterior = factorial(n - 1);
    long long resultadoActual = n * resultadoAnterior;

    // Imprime la resolución del nivel actual (fase de retorno)
    std::cout << "factorial(" << n << ") = " << n << " × " 
              << resultadoAnterior << " = " << resultadoActual << std::endl;

    return resultadoActual;
}

int main() {
    int numero;

    std::cout << "Ingrese un numero entero no negativo: ";
    if (!(std::cin >> numero) || numero < 0) {
        std::cout << "Por favor, ingrese un numero entero valido y mayor o igual a 0." << std::endl;
        return 1;
    }

    std::cout << "\nfactorial de " << numero << ":\n" << std::endl;
    long long resultadoFinal = factorial(numero);

    return 0;
}