#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

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
        if (!huboIntercambio) break;
    }
}

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

bool estaOrdenado(const vector<int>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    // Ruta absoluta exacta
    string nombreArchivo = "C:/Users/hecto/OneDrive/Desktop/Tercer Semestre/Estructura de datos/competencia/diez mil numeros (1).txt";
    ifstream archivo(nombreArchivo);
    vector<int> original;
    int numero;

    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo en la ruta:" << endl;
        cerr << nombreArchivo << endl;
        return 1;
    }

    while (archivo >> numero) {
        original.push_back(numero);
    }
    archivo.close();

    cout << "--- EVALUANDO " << original.size() << " DATOS DEL ARCHIVO ---" << endl << endl;

    // 1. Bubble Sort
    vector<int> copiaBurbuja = original; 
    auto inicioBurbuja = chrono::high_resolution_clock::now();
    bubbleSort(copiaBurbuja);
    auto finBurbuja = chrono::high_resolution_clock::now();
    auto tiempoBurbuja = chrono::duration_cast<chrono::microseconds>(finBurbuja - inicioBurbuja);

    cout << "1. Bubble Sort:" << endl;
    cout << "   - Tiempo: " << tiempoBurbuja.count() << " microsegundos" << endl;
    cout << "   - Estado: " << (estaOrdenado(copiaBurbuja) ? "CORRECTAMENTE ORDENADO" : "ERROR EN ORDENAMIENTO") << endl << endl;

    // 2. Insertion Sort
    vector<int> copiaInsercion = original; 
    auto inicioInsercion = chrono::high_resolution_clock::now();
    insertionSort(copiaInsercion);
    auto finInsercion = chrono::high_resolution_clock::now();
    auto tiempoInsercion = chrono::duration_cast<chrono::microseconds>(finInsercion - inicioInsercion);

    cout << "2. Insertion Sort:" << endl;
    cout << "   - Tiempo: " << tiempoInsercion.count() << " microsegundos" << endl;
    cout << "   - Estado: " << (estaOrdenado(copiaInsercion) ? "CORRECTAMENTE ORDENADO" : "ERROR EN ORDENAMIENTO") << endl << endl;

    // 3. Selection Sort
    vector<int> copiaSeleccion = original; 
    auto inicioSeleccion = chrono::high_resolution_clock::now();
    selectionSort(copiaSeleccion);
    auto finSeleccion = chrono::high_resolution_clock::now();
    auto tiempoSeleccion = chrono::duration_cast<chrono::microseconds>(finSeleccion - inicioSeleccion);

    cout << "3. Selection Sort:" << endl;
    cout << "   - Tiempo: " << tiempoSeleccion.count() << " microsegundos" << endl;
    cout << "   - Estado: " << (estaOrdenado(copiaSeleccion) ? "CORRECTAMENTE ORDENADO" : "ERROR EN ORDENAMIENTO") << endl << endl;

    return 0;
}