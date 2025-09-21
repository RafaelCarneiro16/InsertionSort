#ifndef UTILS_H
#define UTILS_H

typedef struct {
    char modo;
    int tamanho;
} EntradaUsuario;

EntradaUsuario Menu();
void preencherCrescente(int *vetor, int tamanho);
void preencherDecrescente(int *vetor, int tamanho);
void preencherRandomico(int *vetor, int tamanho);
void gerar_crescente(const char* nome, int n);
void gerar_decrescente(const char* nome, int n);
void gerar_random(const char* nome, int n);
void criar_pasta();

#endif // UTILS_H





