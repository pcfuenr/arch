#include <iostream>
#include <chrono>
#include <vector>
#include <bits/stdc++.h>
#include <random>

#include "leer_entrada.cpp"
// Algoritmos de ordenamiento
#include "sort/insertion_sort.cpp"
#include "sort/merge_sort.cpp"
#include "sort/quick_sort.cpp"
#include "sort/heap_sort.cpp"
#include "sort/count_sort.cpp"

// Función para ordenar usando el sort estándar de C++
void STDSort(std::vector<int>& V);

int main(int argc, char* argv[]) {
   // Verificar que se reciban los argumentos necesarios
   if (argc < 3) {
      std::cerr << "Uso: " << argv[0] << " <indice_dataset> <indice_algoritmo>\n";
      return 1;
   }
   // Guardar los argumentos de entrada como enteros
   // El primer argumento es el índice del dataset (1 a 16)
   // El segundo argumento es el índice del algoritmo (1 a 6)
   int dataset  = std::stoi(argv[1]);
   int algoritmo= std::stoi(argv[2]);

   // Inicializar el vector de valores y leer los datos desde un archivo binario
   std::vector<int> valores;
   std::string s_algoritmo;
   std::string s_dataset;

   // Entradas:
   //1. ordenado_ascendente_100mb.bin
   //2. ordenado_ascendente_10mb.bin
   //3. ordenado_ascendente_1mb.bin
   //4. ordenado_ascendente_50mb.bin
   //5. ordenado_descendente_100mb.bin
   //6. ordenado_descendente_10mb.bin
   //7. ordenado_descendente_1mb.bin
   //8. ordenado_descendente_50mb.bin
   //9. parcialmente_ordenado_100mb.bin
   //10. parcialmente_ordenado_10mb.bin
   //11. parcialmente_ordenado_1mb.bin
   //12. parcialmente_ordenado_50mb.bin
   //13. totalmente_desordenado_100mb.bin
   //14. totalmente_desordenado_10mb.bin
   //15. totalmente_desordenado_1mb.bin
   //16. totalmente_desordenado_50mb.bin
   valores = lecturaEntrada(dataset);

   // Asignar el nombre del dataset basado en el índice
   switch (dataset) {
      case 1: s_dataset = "ordenado_ascendente_100mb.bin"; break;
      case 2: s_dataset = "ordenado_ascendente_10mb.bin"; break;
      case 3: s_dataset = "ordenado_ascendente_1mb.bin"; break;
      case 4: s_dataset = "ordenado_ascendente_50mb.bin"; break;
      case 5: s_dataset = "ordenado_descendente_100mb.bin"; break;
      case 6: s_dataset = "ordenado_descendente_10mb.bin"; break;
      case 7: s_dataset = "ordenado_descendente_1mb.bin"; break;
      case 8: s_dataset = "ordenado_descendente_50mb.bin"; break;
      case 9: s_dataset = "parcialmente_ordenado_100mb.bin"; break;
      case 10: s_dataset = "parcialmente_ordenado_10mb.bin"; break;
      case 11: s_dataset = "parcialmente_ordenado_1mb.bin"; break;
      case 12: s_dataset = "parcialmente_ordenado_50mb.bin"; break;
      case 13: s_dataset = "totalmente_desordenado_100mb.bin"; break;
      case 14: s_dataset = "totalmente_desordenado_10mb.bin"; break;
      case 15: s_dataset = "totalmente_desordenado_1mb.bin"; break;
      case 16: s_dataset = "totalmente_desordenado_50mb.bin"; break;
   }

   // Tomar el tiempo que comienza
   auto inicio = std::chrono::high_resolution_clock::now();
   
   // Se elige el algoritmo a utilizar a traves del parametro 'algoritmo', y se transforma el valor a string
   // Opciones: 
   //1. Insertion Sort
   //2. Merge Sort
   //3. Quick Sort
   //4. Heap Sort
   //5. Sort estandar de C++
   //6. Counting Sort
   switch(algoritmo) {
      case 1:
         InsertionSort(valores);
         s_algoritmo = "Insertion Sort";
         break;
      case 2:
         MergeSort(valores, 0, valores.size() - 1);
         s_algoritmo = "Merge Sort";
         break;
      case 3:
         QuickSort(valores, 0, valores.size() - 1);
         s_algoritmo = "Quick Sort";
         break;
      case 4:
         HeapSort(valores);
         s_algoritmo = "Heap Sort";
         break;
      case 5:
         STDSort(valores);
         s_algoritmo = "STD Sort";
         break;
      case 6:
         CountSort(valores);
         s_algoritmo = "Count Sort";
         break;
      default:
         return 1;
   }

   // Tomar el tiempo que finaliza
   auto fin = std::chrono::high_resolution_clock::now();

   // Calcular el tiempo transcurrido
   double tiempo_transcurrido = std::chrono::duration_cast<std::chrono::nanoseconds>(fin - inicio).count();
   tiempo_transcurrido *= 1e-9;

   // Imprimimos el vector ordenado (opcional)
   // for(int i : valores) std::cout << i << " ";

   // Imprimir todo para el .csv
   std::cout << valores.size() << ";" << s_dataset << ";" << s_algoritmo << ";" << tiempo_transcurrido << std::endl;

   return 0;
}

void STDSort(std::vector<int>& V){
   sort(V.begin(), V.end());
}