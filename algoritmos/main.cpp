#include <iostream>
#include <chrono>
#include <vector>
#include <bits/stdc++.h>
#include <random>
#include "leer_entrada.cpp"

void InsertionSort(std::vector<int>& V);
void MergeSort(std::vector<int>& V, int left, int right);
void Merge(std::vector<int>& V, int left, int mid, int right);
void QuickSort(std::vector<int>& V, int left, int right);
int partition(std::vector<int>& V, int left, int right);
void HeapSort(std::vector<int>& V);
void Heapify(std::vector<int>& V, int n, int i);
void STDSort(std::vector<int>& V);
void BubbleSort(std::vector<int>& V);
void Swap(int& A, int& B);

int main(){
   std::vector<int> valores;

   // Crear vector de valores aleatorios
   //int n = 1000000; // Cambia este valor para probar con diferentes tamaños
   //for (int i = 0; i < n; ++i) {
   //    valores.push_back(rand() % 1000000); // Valores aleatorios entre 0 y 999999
   //}

   // Usar Leer_entrada.cpp para obtener el vector de valores
   valores = lecturaEntrada();

   // Tomar el tiempo que comienza
   auto inicio = std::chrono::high_resolution_clock::now();
   
   // Ordenar el vector eligiendo el algoritmo
   InsertionSort(valores);
   //STDSort(valores);
   //MergeSort(valores, 0, valores.size());
   //BubbleSort(valores);
   //HeapSort(valores);
   //QuickSort(valores, 0, valores.size() - 1);

   // Tomar el tiempo que finaliza
   auto fin = std::chrono::high_resolution_clock::now();

   // Calculamos el tiempo transcurrido
   double tiempo_transcurrido = std::chrono::duration_cast<std::chrono::nanoseconds>(fin - inicio).count();
   tiempo_transcurrido *= 1e-9;

   // Imprimimos el resultado
   std::cout << ";" << tiempo_transcurrido << std::endl;

   // Imprimimos el vector ordenado (opcional)
   // for(int i : valores) std::cout << i << " ";

   return 0;
}

void InsertionSort(std::vector<int>& V){
   for(int i : V) {
        int key = V[i];
        int j = i - 1;

        while (j >= 0 && V[j] > key) {
            V[j + 1] = V[j];
            j = j - 1;
        }
        V[j + 1] = key;
    }
}

void MergeSort(std::vector<int>& V, int left, int right){
   if (left >= right)
      return;

   int mid = left + (right - left) / 2;
   MergeSort(V, left, mid);
   MergeSort(V, mid + 1, right);
   Merge(V, left, mid, right);
}

void Merge(std::vector<int>& V, int left, int mid, int right){
   int n1 = mid - left + 1;
   int n2 = right - mid;

   std::vector<int> L(n1), R(n2);

   for (int i = 0; i < n1; i++)
      L[i] = V[left + i];
   for (int j = 0; j < n2; j++)
      R[j] = V[mid + 1 + j];

   int i = 0, j = 0;
   int k = left;

   while (i < n1 && j < n2) {
      if (L[i] <= R[j]) {
         V[k] = L[i];
         i++;
      }
      else {
         V[k] = R[j];
         j++;
      }
      k++;
   }

   while (i < n1) {
      V[k] = L[i];
      i++;
      k++;
   }

   while (j < n2) {
      V[k] = R[j];
      j++;
      k++;
   }
}

void QuickSort(std::vector<int>& V, int left, int right){
   if (left < right) {
        int pi = partition(V, left, right);

        QuickSort(V, left, pi - 1);
        QuickSort(V, pi + 1, right);
    }

}

int partition(std::vector<int>& V, int left, int right) {
    // pivote al azar
    int rnd = left + rand() % (right - left + 1);
    Swap(V[rnd], V[right]);
    int pivote = V[rnd];

    int i = left - 1;

    for (int j = left; j <= right - 1; j++) {
        if (V[j] <= pivote) {
            i++;
            Swap(V[i], V[j]);
        }
    }
    
    Swap(V[i + 1], V[right]);  
    return i + 1;
}

void HeapSort(std::vector<int>& V){
   int n = V.size(); 
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(V, n, i);

    for (int i = n - 1; i > 0; i--) {
        Swap(V[0], V[i]);
        Heapify(V, i, 0);
    }
}

void Heapify(std::vector<int>& V, int n, int i){
    int largest = i;

    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && V[l] > V[largest])
        largest = l;

    if (r < n && V[r] > V[largest])
        largest = r;

    if (largest != i) {
        Swap(V[i], V[largest]);
        Heapify(V, n, largest);
    }
}

void STDSort(std::vector<int>& V){
   sort(V.begin(), V.end());
}

void BubbleSort(std::vector<int>& V){
   int n = V.size();
    bool swapped;
  
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (V[j] > V[j + 1]) {
               Swap(V[j], V[j + 1]);
               swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void Swap(int& A, int& B){
   int aux = A;
   A = B;
   B = aux;
}
