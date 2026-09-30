#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;

// 1. Algoritmo de Ordenamiento por Burbuja (Bubble Sort)
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        bool huboIntercambio = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                huboIntercambio = true;
            }
        }
        // Optimización: Si no hubo intercambios en la pasada, ya está ordenado
        if (!huboIntercambio) break;
    }
}

// 2. Algoritmo de Ordenamiento por Inserción (Insertion Sort)
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int clave = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > clave) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = clave;
    }
}

// 3. Algoritmo de Ordenamiento por Selección (Selection Sort)
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int idxMinimo = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[idxMinimo]) {
                idxMinimo = j;
            }
        }
        if (idxMinimo != i) {
            swap(arr[i], arr[idxMinimo]);
        }
    }
}

// Función auxiliar para verificar si el vector está correctamente ordenado
bool estaOrdenado(const vector<int>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    const int N = 1000; // Tamaño de la muestra (mínimo 1000)

    // Generar un arreglo con números aleatorios
    vector<int> original(N);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 10000);

    for (int i = 0; i < N; ++i) {
        original[i] = dis(gen);
    }

    cout << "==================================================" << endl;
    cout << "  COMPETENCIA DE ALGORITMOS DE ORDENAMIENTO (" << N << " elementos)" << endl;
    cout << "==================================================" << endl << endl;

    // ---------------------------------------------------------------------
    // Competidor 1: Bubble Sort
    // ---------------------------------------------------------------------
    vector<int> copiaBurbuja = original; // Copia independiente

    auto inicioBurbuja = chrono::high_resolution_clock::now();
    bubbleSort(copiaBurbuja);
    auto finBurbuja = chrono::high_resolution_clock::now();

    auto tiempoBurbuja = chrono::duration_cast<chrono::microseconds>(finBurbuja - inicioBurbuja);

    cout << "1. Bubble Sort:" << endl;
    cout << "   - Tiempo: " << tiempoBurbuja.count() << " microsegundos" << endl;
    cout << "   - Estado: " << (estaOrdenado(copiaBurbuja) ? " CORRECTAMENTE ORDENADO" : " ERROR EN ORDENAMIENTO") << endl << endl;

    // ---------------------------------------------------------------------
    // Competidor 2: Insertion Sort
    // ---------------------------------------------------------------------
    vector<int> copiaInsercion = original; // Copia independiente

    auto inicioInsercion = chrono::high_resolution_clock::now();
    insertionSort(copiaInsercion);
    auto finInsercion = chrono::high_resolution_clock::now();

    auto tiempoInsercion = chrono::duration_cast<chrono::microseconds>(finInsercion - inicioInsercion);

    cout << "2. Insertion Sort:" << endl;
    cout << "   - Tiempo: " << tiempoInsercion.count() << " microsegundos" << endl;
    cout << "   - Estado: " << (estaOrdenado(copiaInsercion) ? " CORRECTAMENTE ORDENADO" : " ERROR EN ORDENAMIENTO") << endl << endl;

    // ---------------------------------------------------------------------
    // Competidor 3: Selection Sort
    // ---------------------------------------------------------------------
    vector<int> copiaSeleccion = original; // Copia independiente

    auto inicioSeleccion = chrono::high_resolution_clock::now();
    selectionSort(copiaSeleccion);
    auto finSeleccion = chrono::high_resolution_clock::now();

    auto tiempoSeleccion = chrono::duration_cast<chrono::microseconds>(finSeleccion - inicioSeleccion);

    cout << "3. Selection Sort:" << endl;
    cout << "   - Tiempo: " << tiempoSeleccion.count() << " microsegundos" << endl;
    cout << "   - Estado: " << (estaOrdenado(copiaSeleccion) ? " CORRECTAMENTE ORDENADO" : " ERROR EN ORDENAMIENTO") << endl << endl;

    cout << "==================================================" << endl;

    return 0;
}