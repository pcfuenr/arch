// Implementación del algoritmo Merge Sort
#include <iostream>
#include <vector>

void MergeSort(std::vector<int>& V, int left, int right);
void Merge(std::vector<int>& V, int left, int mid, int right);

// Función principal de Merge Sort
// V: vector a ordenar, left: índice inicial, right: índice final
void MergeSort(std::vector<int>& V, int left, int right) {
    // Caso base: subarray de uno o cero elementos ya está ordenado
    if (left >= right)
        return;

    // Calcula el punto medio evitando overflow
    int mid = left + (right - left) / 2;

    // Ordena recursivamente la mitad izquierda
    MergeSort(V, left, mid);
    // Ordena recursivamente la mitad derecha
    MergeSort(V, mid + 1, right);
    // Fusiona ambas mitades ordenadas
    Merge(V, left, mid, right);
}

// Fusiona dos subarrays de V: [left..mid] y [mid+1..right]
void Merge(std::vector<int>& V, int left, int mid, int right) {
    int n1 = mid - left + 1;  // tamaño de la subarray izquierda
    int n2 = right - mid;     // tamaño de la subarray derecha

    // Copia los elementos en vectores temporales L y R
    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = V[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = V[mid + 1 + j];

    // Índices para recorrer L, R y V
    int i = 0, j = 0, k = left;

    // Mezcla mientras queden elementos en ambas mitades
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            V[k] = L[i];
            i++;
        } else {
            V[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia los elementos restantes de L (si los hay)
    while (i < n1) {
        V[k] = L[i];
        i++;
        k++;
    }

    // Copia los elementos restantes de R (si los hay)
    while (j < n2) {
        V[k] = R[j];
        j++;
        k++;
    }
}