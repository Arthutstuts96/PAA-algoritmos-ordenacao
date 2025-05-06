#include <stdio.h>
#include "functions.h"

int main(){
    int A[] = {8, 7, 3, 5, 4, 6, 2, 1};
    int tamanho = sizeof(A) / sizeof(A[0]);
    printf("Tamanho: %d\n", tamanho);
    
    bubble_sort(A, tamanho);
    
    printf("Lista ordenada: ");

    for (int i = 0; i < tamanho; i++){
        printf("%d, ", A[i]);
    }
    

    return 0;
}