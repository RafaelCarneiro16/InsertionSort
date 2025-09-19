#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct {
    char modo;
    int tamanho;
} EntradaUsuario;

EntradaUsuario Menu();
void preencherCrescente(int *vetor, int tamanho);
void preencherDecrescente(int *vetor, int tamanho);
void preencherRandomico(int *vetor, int tamanho);


#endif  