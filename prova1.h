#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Funcionario
{
    int code;
    char nome[50];
    char data_nascimento[11];
    int salario;
} TFunc;

typedef struct key_sorting
{
    int code;
    long RRN;
} Key_Sorting;

void leFunc(TFunc funcs);
void createFunc(TFunc *funcs, int n);
void createArq(TFunc *funcs, FILE *arq, int n);
void createArqByOne(TFunc func, FILE *ordenado, int i);
TFunc readFile(FILE *arq, int i);
void sequencial(int code, FILE *arq, int tamanho);
void busca_binaria(int code, FILE *arq, int tam);
void keySorting(FILE *arq, FILE *ordenado, int tamanho);
TFunc readFileWithByte(FILE *arq);
void insertionSort(FILE *ordenado, int tamanho);
