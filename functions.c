#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

// Funções auxiliares
/*
    Troca os valores de duas variáveis
*/
void trocaValor(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}
/*
    Justa os dois vetores e retorna um terceiro ordenado para a função merge sort
*/
void merge(int* vetor, int inicio, int meio, int fim){
    int i = 0;
    int j = 0;
    int k = inicio;
    int tamanhoLadoEsquerdo = meio - inicio + 1;
    int tamanhoLadoDireito = fim - meio;

    //Cria vetores temporários para cada lado, alocando memória
    int* ladoEsquerdo = malloc(sizeof(int) * tamanhoLadoEsquerdo);
    int* ladoDireito = malloc(sizeof(int) * tamanhoLadoDireito);
    if(ladoDireito && ladoEsquerdo){
        while(i < tamanhoLadoEsquerdo){
            ladoEsquerdo[i] = vetor[meio + 1 + i];
            i++;
        }
        while(j < tamanhoLadoDireito){
            ladoDireito[j] = vetor[inicio + j];
            j++;
        }
    }
    i = 0;
    j = 0;

    //Compara os valores para ordená-los no vetor
    while (i < tamanhoLadoEsquerdo && j < tamanhoLadoDireito) {
        if (ladoEsquerdo[i] <= ladoDireito[j]) {
            vetor[k] = ladoEsquerdo[i];
            i++;
        }
        else {
            vetor[k] = ladoDireito[j];
            j++;
        }
        k++;
    }

    //Copia o resto dos elementos de ambos arrays, se tiverem
    while (i < tamanhoLadoEsquerdo) {
        vetor[k] = ladoEsquerdo[i];
        i++;
        k++;
    }
    while (j < tamanhoLadoDireito) {
        vetor[k] = ladoDireito[j];
        j++;
        k++;
    }

    free(ladoDireito);
    free(ladoEsquerdo);
}
/*
    Particiona o vetor em 3 partes para a função quick sort
*/
int partition(int* vetor, int inicio, int fim){
    int v = vetor[fim];
    int q = inicio - 1;

    for(int i = inicio; i <= fim - 1; i++){
        if(vetor[i] < v){
            q++;
            trocaValor(&vetor[i], &vetor[q]);
        }
    }
    trocaValor(&vetor[fim], &vetor[q + 1]);
    return q + 1;
}

/* Algoritmos */

void bubble_sort(int* vetor, int tamanho){
    for (int i = 0; i < tamanho; i++){
        for (int j = tamanho - 1; j > i; j--){
            if(vetor[j] < vetor[j - 1]){
                trocaValor(&vetor[j], &vetor[j - 1]);
            }
        }
    }
}
void insertion_sort(int* vetor, int tamanho){
    for (int j = 0; j < tamanho; j++){
        int key = vetor[j];
        int i = j - 1;
        while(i >= 0 && vetor[i] > key){
            vetor[i + 1] = vetor[i];
            i--;
        }
        vetor[i + 1] = key;
    }
}
void selection_sort(int* vetor, int tamanho){
    for(int i = 0; i < tamanho - 1; i++){
        int menorValor = i;
        for(int j = i + 1; j < tamanho; j++){
            if(vetor[j] < vetor[menorValor]){
                menorValor = j;
            }
        }
        trocaValor(&vetor[i], &vetor[menorValor]);
    }
}
void merge_sort(int* vetor, int inicio, int fim){
    if(inicio < fim){
        int meio = inicio + (fim - inicio) / 2;
    
        merge_sort(vetor, inicio, meio);
        merge_sort(vetor, meio + 1, fim);
    
        merge(vetor, inicio, meio, fim);
    }
}
void quick_sort(int* vetor, int inicio, int fim){
    if(inicio < fim){
        int q = partition(vetor, inicio, fim);

        quick_sort(vetor, inicio, q - 1);
        quick_sort(vetor, q + 1, fim);
    }
}
void heap_sort(int* vetor, int tamanho){

}
