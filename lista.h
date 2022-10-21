#include <stdio.h>
#include <stdlib.h>


typedef struct No {
    int valor;
    long RRN;
    struct No *proximo;
} No;

typedef struct {
    No *inicio, *fim;
    int tam;
} Lista;

void inserirInicio(Lista *lista, int valor, long RRN);
void inserirFim(Lista *lista, int valor, long RRN);
void imprimir(Lista *lista);
