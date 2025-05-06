#include "functions.h"
#include <stdio.h>

/* Funções auxiliares */

void exchange(int* a, int* b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

/* Algoritmos */

void bubble_sort(int* vetor, int tamanho){
    for (int i = 0; i < tamanho; i++){
        for (int j = tamanho - 1; j > i; j--){
            if(vetor[j] < vetor[j - 1]){
                exchange(&vetor[j], &vetor[j - 1]);
            }
        }
    }
}
int* selection_sort(int* vetor){

}
int* insertion_sort(int* vetor){

}
int* merge_sort(int* vetor){

}
int* quick_sort(int* vetor){

}
int* heap_sort(int* vetor){

}
