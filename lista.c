#include <stdio.h>
#include <stdlib.h>
#include "./lista.h"

void inserirInicio(Lista *lista, int valor, long RRN)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->RRN = RRN;

    if (lista->inicio == NULL)
    {
        novo->proximo = NULL;
        lista->inicio = novo;
        lista->fim = novo;
    }
    else
    {
        novo->proximo = lista->inicio;
        lista->inicio = novo;
    }
    lista->tam++;
}

void inserirFim(Lista *lista, int valor, long RRN)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->RRN = RRN;
    novo->proximo = NULL;

    if (lista->inicio == NULL)
    {
        lista->inicio = novo;
        lista->fim = novo;
    }
    else
    {
        lista->fim->proximo = novo;
        lista->fim = novo;
    }
    lista->tam++;
}

void imprimir(Lista *lista)
{
    No *inicio = lista->inicio;

    printf("\n\n[\t", inicio->valor);
    while (inicio != NULL)
    {
        printf("%d\t", inicio->valor);
        // printf("%d] ", inicio->RRN);
        inicio = inicio->proximo;
    }
    printf("]\n\n");
}
