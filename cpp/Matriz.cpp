#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;

int main() {
    int filas, columnas;

    // 1. Solicitar filas y columnas
    cout << "Ingrese el numero de filas: ";
    cin >> filas;
    cout << "Ingrese el numero de columnas: ";
    cin >> columnas;

    if (filas <= 0 || columnas <= 0) {
        cout << "El número de filas y columnas debe ser mayor a 0." << endl;
        return 1;
    }

    vector<vector<int>> matriz(filas, vector<int>(columnas));

    // 2. Capturar los elementos de la matriz
    cout << "\n--- Captura de Elementos ---" << endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << "Matriz[" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    // Variables para cálculos
    int sumaTotal = 0;
    int mayor = numeric_limits<int>::min();
    int menor = numeric_limits<int>::max();

    // 3. Mostrar la matriz en forma de tabla
    cout << "\n--- Matriz Capturada ---" << endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << setw(6) << matriz[i][j] << " ";
            
            // Procesar suma total, mayor y menor durante la lectura
            int valorActual = matriz[i][j];
            sumaTotal += valorActual;
            if (valorActual > mayor) mayor = valorActual;
            if (valorActual < menor) menor = valorActual;
        }
        cout << endl;
    }

    // 4. Mostrar suma total, promedio, mayor y menor
    double promedio = static_cast<double>(sumaTotal) / (filas * columnas);

    cout << "\n--- Resultados Generales ---" << endl;
    cout << "Suma de todos los elementos: " << sumaTotal << endl;
    cout << "Promedio de los elementos: " << fixed << setprecision(2) << promedio << endl;
    cout << "Valor mayor: " << mayor << endl;
    cout << "Valor menor: " << menor << endl;

    // 5. Calcular y mostrar la suma de cada fila
    cout << "\n--- Suma por Filas ---" << endl;
    for (int i = 0; i < filas; ++i) {
        int sumaFila = 0;
        for (int j = 0; j < columnas; ++j) {
            sumaFila += matriz[i][j];
        }
        cout << "Fila " << i + 1 << ": " << sumaFila << endl;
    }

    // 6. Calcular y mostrar la suma de cada columna
    cout << "\n--- Suma por Columnas ---" << endl;
    for (int j = 0; j < columnas; ++j) {
        int sumaColumna = 0;
        for (int i = 0; i < filas; ++i) {
            sumaColumna += matriz[i][j];
        }
        cout << "Columna " << j + 1 << ": " << sumaColumna << endl;
    }

    return 0;
}