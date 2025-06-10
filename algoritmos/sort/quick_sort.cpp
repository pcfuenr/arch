// Implementación del algoritmo Quick Sort en C++
#include <iostream>
#include <vector>
#include <algorithm>

void QuickSort(std::vector<int>& V, int left, int right);
int partition(std::vector<int>& V, int left, int right);
void Swap(int& a, int& b);

// Función principal de Quick Sort
// V: vector a ordenar, left y right: índices de subarray a procesar
void QuickSort(std::vector<int>& V, int left, int right) {
    // Si hay al menos dos elementos, continuar
    if (left < right) {
        // Particiona y obtiene índice final del pivote
        int pi = partition(V, left, right);
        // Ordena recursivamente la parte izquierda al pivote
        QuickSort(V, left, pi - 1);
        // Ordena recursivamente la parte derecha al pivote
        QuickSort(V, pi + 1, right);
    }
}

// Particiona el vector en torno a un pivote aleatorio
// Devuelve la posición final del pivote
int partition(std::vector<int>& V, int left, int right) {
    // Selecciona un índice aleatorio entre left y right
    int rnd = left + rand() % (right - left + 1);
    // Mueve el elemento aleatorio al final para usarlo como pivote
    Swap(V[rnd], V[right]);
    int pivote = V[right];

    // i marca el último elemento menor o igual al pivote
    int i = left - 1;
    // Recorre el subarray para acomodar elementos <= pivote a la izquierda
    for (int j = left; j <= right - 1; j++) {
        if (V[j] <= pivote) {
            i++;
            Swap(V[i], V[j]); // intercambia para mantener partición
        }
    }
    // Coloca el pivote justo después de los menores o iguales
    Swap(V[i + 1], V[right]);
    return i + 1;
}

// Intercambia dos enteros por referencia
void Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}