#include <iostream>
#include <cmath>

using namespace std;

// Función recursiva para resolver y mostrar los movimientos
void torresDeHanoi(int n, char origen, char auxiliar, char destino) {
    if (n == 1) {
        cout << "Mover disco 1 de " << origen << " a " << destino << "\n";
        return;
    }
    
    // 1. Mover n-1 discos de origen a auxiliar usando destino
    torresDeHanoi(n - 1, origen, destino, auxiliar);
    
    // 2. Mover el disco restante (n) de origen a destino
    cout << "Mover disco " << n << " de " << origen << " a " << destino << "\n";
    
    // 3. Mover n-1 discos de auxiliar a destino usando origen
    torresDeHanoi(n - 1, auxiliar, origen, destino);
}

int main() {
    int n;
    cout << "--- TORRES DE HANOI ---\n";
    cout << "Ingrese el numero de discos: ";
    cin >> n;

    if (n <= 0) {
        cout << "El numero de discos debe ser mayor a 0.\n";
        return 1;
    }

    if (n <= 10) {
        cout << "\nPasos requeridos:\n";
        torresDeHanoi(n, 'A', 'B', 'C');
    } else {
        cout << "\n[Aviso] No se imprimen los pasos debido al gran volumen de salida.\n";
    }

    unsigned long long movimientos = pow(2, n) - 1;
    cout << "\nTotal de movimientos requeridos para " << n << " discos: " << movimientos << "\n";

    return 0;
}