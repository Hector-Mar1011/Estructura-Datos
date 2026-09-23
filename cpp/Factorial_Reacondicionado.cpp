#include <iostream>
#include <limits> // Necesario para std::numeric_limits

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

    // Bucle de validación para asegurar un entero no negativo
    while (true) {
        std::cout << "Ingrese un numero entero no negativo: ";
        
        if (std::cin >> numero && numero >= 0) {
            break; // Entrada válida, sale del bucle
        }

        // Si la entrada no es un entero o es negativa
        std::cout << "Error: Valor no valido. Por favor, introduzca un numero entero mayor o igual a 0.\n" << std::endl;
        
        // Limpia el estado de error de std::cin
        std::cin.clear();
        // Descarta la entrada incorrecta del buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "\nfactorial de " << numero << ":\n" << std::endl;
    long long resultadoFinal = factorial(numero);

    return 0;
}