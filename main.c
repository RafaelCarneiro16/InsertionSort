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
    int opcao;
    do {
        printf("\nMenu Principal\n");
        printf("1 - Gerar arquivos de entrada\n");
        printf("2 - Executar ordenação\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            // Geração dos arquivos de entrada
            int tamanhos[] = {10, 100, 1000, 10000, 100000, 1000000};
            int n_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);
            criar_pasta();
            for (int i = 0; i < n_tamanhos; i++) {
                char nome[64];
                snprintf(nome, sizeof(nome), "entradacrescente%d.txt", tamanhos[i]);
                gerar_crescente(nome, tamanhos[i]);
                snprintf(nome, sizeof(nome), "entradadecrescente%d.txt", tamanhos[i]);
                gerar_decrescente(nome, tamanhos[i]);
                snprintf(nome, sizeof(nome), "entradarandom%d.txt", tamanhos[i]);
                gerar_random(nome, tamanhos[i]);
            }
            printf("Arquivos de entrada gerados em C:/arquivodeentrada/\n");
        } else if (opcao == 2) {
            EntradaUsuario entrada = Menu();
            if (entrada.modo == 's' || entrada.tamanho == 0) {
                printf("Voltando ao menu principal.\n");
                continue;
            }
            int *vetor = (int *)malloc(entrada.tamanho * sizeof(int));
            if (vetor == NULL) {
                printf("Erro ao alocar memoria.\n");
                continue;
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
        } else if (opcao == 0) {
            printf("Programa encerrado.\n");
        } else {
            printf("Opção inválida.\n");
        }
    } while (opcao != 0);
    return 0;
}

