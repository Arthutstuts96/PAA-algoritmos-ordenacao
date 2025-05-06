#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/* Lista de 1000, 10000, 50000 e 100000 entradas
Ordenada
Inversamente ordenada
Aleatória

Tempo de execução (em milissegundos)
Número de comparações
Número de trocas
*/

void bubble_sort(int *, int);
void selection_sort(int *, int);
void insertion_sort(int *, int);
void merge_sort(int *, int, int);
void quick_sort(int *, int, int);
void heap_sort(int *, int);

#endif