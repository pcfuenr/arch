// Implementación del algoritmo Counting Sort
#include <iostream>
#include <vector>
#include <algorithm>

void CountSort(std::vector<int>& V);

void CountSort(std::vector<int>& V) {
    if (V.empty()) return;

    // Encuentra el valor máximo para definir el rango
    int max_val = *std::max_element(V.begin(), V.end());
    int min_val = *std::min_element(V.begin(), V.end());
    int range = max_val - min_val + 1;

    // Crea el vector de conteo e inicialízalo en 0
    std::vector<int> count(range, 0);

    // Cuenta las ocurrencias de cada valor
    for (int num : V) {
        count[num - min_val]++;
    }

    // Reconstruye el vector ordenado
    V.clear();
    for (int i = 0; i < range; i++) {
        V.insert(V.end(), count[i], i + min_val);
    }
}