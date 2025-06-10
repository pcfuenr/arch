// Implementación del algoritmo Heap Sort
#include <iostream>
#include <vector>
#include <algorithm>

void HeapSort(std::vector<int>& V);
void Heapify(std::vector<int>& V, int n, int i);

void HeapSort(std::vector<int>& V) {
    int n = V.size();

    // Construir el heap (reordenar el vector)
    for (int i = n / 2 - 1; i >= 0; i--) {
        Heapify(V, n, i);
    }

    // Extraer elementos del heap uno por uno
    for (int i = n - 1; i > 0; i--) {
        std::swap(V[0], V[i]); // Mover el elemento actual al final
        Heapify(V, i, 0); // Llamar a Heapify en el heap reducido
    }
}

void Heapify(std::vector<int>& V, int n, int i) {
    int largest = i; // Inicializar el nodo raíz como el más grande
    int left = 2 * i + 1; // Hijo izquierdo
    int right = 2 * i + 2; // Hijo derecho

    // Si el hijo izquierdo es mayor que el nodo raíz
    if (left < n && V[left] > V[largest])
        largest = left;

    // Si el hijo derecho es mayor que el más grande hasta ahora
    if (right < n && V[right] > V[largest])
        largest = right;

    // Si el más grande no es el nodo raíz
    if (largest != i) {
        std::swap(V[i], V[largest]); // Intercambiar
        Heapify(V, n, largest); // Recursivamente heapificar el subárbol afectado
    }
}