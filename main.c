#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "functions.h"

int* ler_arquivo(const char* nome_arquivo, int* tamanho) {
    char caminho[100];
    snprintf(caminho, sizeof(caminho), "entradas/%s", nome_arquivo);

    FILE* arquivo = fopen(caminho, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        *tamanho = 0;
        return NULL;
    }

    int capacidade = 10;
    int* vetor = malloc(capacidade * sizeof(int));
    if (vetor == NULL) {
        perror("Erro ao alocar memória");
        fclose(arquivo);
        *tamanho = 0;
        return NULL;
    }

    int valor;
    *tamanho = 0;
    while (fscanf(arquivo, "%d", &valor) == 1) {
        if (*tamanho >= capacidade) {
            capacidade *= 2;
            int* temp = realloc(vetor, capacidade * sizeof(int));
            if (temp == NULL) {
                perror("Erro ao realocar memória");
                free(vetor);
                fclose(arquivo);
                *tamanho = 0;
                return NULL;
            }
            vetor = temp;
        }
        vetor[*tamanho] = valor;
        (*tamanho)++;
    }

    fclose(arquivo);
    return vetor;
}

void print_vetor(int* A, int tamanho){
  for (int i = 0; i < tamanho; i++){
      printf("[%d]", A[i]);
  }
}

int main() {
    int opcao_alg, opcao_entrada;
    char* nomes_arquivos[] = {
        "entrada-1k.txt",
        "entrada-10k.txt",
        "entrada-50k.txt",
        "entrada-100k.txt"
    };

    while (1) {
        printf("\n==== SELECIONE O ARQUIVO DE ENTRADA ====\n");
        printf("1 - 1.000 elementos\n");
        printf("2 - 10.000 elementos\n");
        printf("3 - 50.000 elementos\n");
        printf("4 - 100.000 elementos\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao_entrada);

        if (opcao_entrada == 0) {
            printf("Encerrando programa.\n");
            break;
        }

        if (opcao_entrada < 1 || opcao_entrada > 4) {
            printf("Opcao de entrada invalida.\n");
            continue;
        }

        printf("\n==== SELECIONE O ALGORITMO DE ORDENACAO ====\n");
        printf("1 - Bubble Sort\n");
        printf("2 - Insertion Sort\n");
        printf("3 - Selection Sort\n");
        printf("4 - Merge Sort\n");
        printf("5 - Quick Sort\n");
        printf("0 - Voltar ao menu anterior\n");
        printf("Opcao: ");
        scanf("%d", &opcao_alg);

        if (opcao_alg == 0) continue;
        if (opcao_alg < 1 || opcao_alg > 5) {
            printf("Opcao de algoritmo invalida.\n");
            continue;
        }

        int tamanho;
        int* vetor = ler_arquivo(nomes_arquivos[opcao_entrada - 1], &tamanho);
        if (!vetor) continue;

        clock_t inicio = clock();

        switch (opcao_alg) {
            case 1: bubble_sort(vetor, tamanho); break;
            case 2: insertion_sort(vetor, tamanho); break;
            case 3: selection_sort(vetor, tamanho); break;
            case 4: merge_sort(vetor, 0, tamanho - 1); break;
            case 5: quick_sort(vetor, 0, tamanho - 1); break;
        }

        clock_t fim = clock();
        double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

        printf("\nArquivo: %s\n", nomes_arquivos[opcao_entrada - 1]);
        printf("Algoritmo: ");
        switch (opcao_alg) {
            case 1: printf("Bubble Sort"); break;
            case 2: printf("Insertion Sort"); break;
            case 3: printf("Selection Sort"); break;
            case 4: printf("Merge Sort"); break;
            case 5: printf("Quick Sort"); break;
        }
        printf("\n-- Tempo de execucao: %.15f segundos\n", tempo);

        free(vetor);
    }

    return 0;
}