#include "utils.h"

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

