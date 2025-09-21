#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "utils.h"

#define DIR "C:/arquivodeentrada/"

void gerar_crescente(const char* nome, int n) {
    char caminho_arquivo[256];
    snprintf(caminho_arquivo, sizeof(caminho_arquivo), "%s%s", DIR, nome);
    FILE* f = fopen(caminho_arquivo, "w");
    for (int i = 1; i <= n; i++) {
        fprintf(f, "%d\n", i);
    }
    fclose(f);
}

void gerar_decrescente(const char* nome, int n) {
    char caminho_arquivo[256];
    snprintf(caminho_arquivo, sizeof(caminho_arquivo), "%s%s", DIR, nome);
    FILE* f = fopen(caminho_arquivo, "w");
    for (int i = n; i >= 1; i--) {
        fprintf(f, "%d\n", i);
    }
    fclose(f);
}

void gerar_random(const char* nome, int n) {
    char caminho_arquivo[256];
    snprintf(caminho_arquivo, sizeof(caminho_arquivo), "%s%s", DIR, nome);
    FILE* f = fopen(caminho_arquivo, "w");
    for (int i = 0; i < n; i++) {
        fprintf(f, "%d\n", rand() % (n * 10));
    }
    fclose(f);
}

void criar_pasta() {
    CreateDirectoryA(DIR, NULL);
}

EntradaUsuario Menu() {
    EntradaUsuario entrada;
    int valido = 0;

    printf("-------------------------\n"
           "Legenda:\n"
           "-------------------------\n"
           "r - Randomicos\n"
           "c - Crescentes\n"
           "d - Decrescentes\n"
           "s - Sair\n"
           "-------------------------\n");

    // Escolher uma ordem valida
    do {
        printf("Escolha uma opcao: ");
        scanf(" %c", &entrada.modo);

        if (entrada.modo == 's') {
            printf("Opcao Sair selecionada.\n");
            entrada.tamanho = 0;
            return entrada;
        }

        if (entrada.modo != 'r' && entrada.modo != 'c' && entrada.modo != 'd') {
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (entrada.modo != 'r' && entrada.modo != 'c' && entrada.modo != 'd');

    // Inserir um tamanho valido
    do {
        printf("Entre as opcoes validas (10, 100, 1000, 10000, 100000, 1000000):\n");
        printf("Escolha o tamanho do vetor: ");
        scanf("%d", &entrada.tamanho);

        if ((entrada.tamanho == 10 || entrada.tamanho == 100 || entrada.tamanho == 1000 ||
             entrada.tamanho == 10000 || entrada.tamanho == 100000 || entrada.tamanho == 1000000)) {

            valido = 1;
            
        } else {
            printf("Tamanho invalido. Tente novamente.\n");
        }
    } while (!valido);

    return entrada;
}

void preencherCrescente(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = i + 1;
    }
}

void preencherDecrescente(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = tamanho - i;
    }
}

void preencherRandomico(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 10000;
    }
}

