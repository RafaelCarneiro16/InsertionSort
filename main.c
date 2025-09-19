#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utils.h"

void InsertionSort(int entradas, int *vetor){
    int i, j, key;

    for (i = 1; i < entradas; i++){
        key = vetor[i];
        j = i - 1;
    
        while (j >= 0 && vetor[j] > key){
            vetor[j + 1] = vetor[j];
            j--;
        }

        vetor[j + 1] = key;
    }
}

int main() {
    srand(time(NULL));
    EntradaUsuario entrada = Menu();

    if (entrada.modo == 's' || entrada.tamanho == 0) {
        printf("Programa encerrado.\n");
        return 0;
    }

    int *vetor = (int *)malloc(entrada.tamanho * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    // Preencher o vetor conforme a opção
    switch (entrada.modo) {
        case 'r':
            printf("Preenchendo vetor com valores randomicos...\n");
            preencherRandomico(vetor, entrada.tamanho);
            break;
        case 'c':
            printf("Preenchendo vetor de forma crescente...\n");
            preencherCrescente(vetor, entrada.tamanho);
            break;
        case 'd':
            printf("Preenchendo vetor de forma decrescente...\n");
            preencherDecrescente(vetor, entrada.tamanho);
            break;
    }

    printf("Ordenando vetor...\n");
    InsertionSort(entrada.tamanho, vetor);
    printf("Vetor ordenado!\n");

    free(vetor);
    return 0;
}

