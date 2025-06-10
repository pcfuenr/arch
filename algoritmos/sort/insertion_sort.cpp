// Implementación del algoritmo Insertion Sort
#include <iostream>
#include <vector>

void InsertionSort(std::vector<int>& V);

void InsertionSort(std::vector<int>& V) {
    // 1) Recorre el vector desde el segundo elemento (índice 1)
    for (int i = 1; i < V.size(); i++) {
        // 2) Guarda el elemento actual como 'clave'
        int key = V[i];
        // 3) Empieza a comparar con el elemento anterior
        int j = i - 1;

        // 4) Mientras queden elementos a la izquierda y sean mayores
        //    que 'key', desplaza esos elementos una posición a la derecha
        while (j >= 0 && V[j] > key) {
            V[j + 1] = V[j];
            j--;
        }

        // 5) Inserta la 'key' en la posición correcta
        V[j + 1] = key;
    }
}