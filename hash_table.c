#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"
#include "./lista.h"

void init(THash *hash, int n)
{
    hash->tamanho = 0;

    for (int i = 0; i < n; i++)
    {
        hash->func[i].code = -1;
        hash->func[i].RRN = 0;
    }
}

void insert_hash(THash *hash, Key_Sorting item, int n)
{

    int mod = item.code % n;

    if (hash->func[mod].code != -1)
    {
        printf("\n ******** ERRO! Indice %i ocupado ******** \n", mod);

        return;
    }

    hash->func[mod] = item;
    hash->tamanho++;

    printf("\n############## Espaco %i, Funcionario %i inserido com sucesso ##############\n\n", mod, item.code);
}

void create_many(THash *hash, TFunc *funcs, int n, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        int mod = funcs[i].code % n;

        if (hash->func[mod].code != -1)
        {
            continue;
        }

        hash->func[mod].code = funcs[i].code;
        hash->func[mod].RRN = i * sizeof(TFunc);
        hash->tamanho++;
    }
}

void to_string_hash(THash *hash, int n)
{

    for (int i = 0; i < n; i++)
    {
        if (hash->func[i].code == -1)
        {
            printf("\n Espaco %i Vazio\n", i);

            continue;
        }

        printf("\n############## Espaco %i, Funcionario %i, Endereco %i ##############\n", i, hash->func[i].code, hash->func[i].RRN);
    }
}

void create_many_withTreatment(FILE *arq, int tamanho)
{
    arq = fopen("binario.dat", "rb");
    FILE *arq0 = fopen("0.dat", "rb+");
    FILE *arq1 = fopen("1.dat", "rb+");
    FILE *arq2 = fopen("2.dat", "rb+");
    FILE *arq3 = fopen("3.dat", "rb+");
    FILE *arq4 = fopen("4.dat", "rb+");
    FILE *arq5 = fopen("5.dat", "rb+");
    FILE *arq6 = fopen("6.dat", "rb+");
    Lista lista[7];
    rewind(arq);
    long RRN;

    for (int i = 0; i < 7; i++)
    {
        lista[i].inicio = NULL;
        lista[i].fim = NULL;
        lista[i].tam = 0;
    }

    int addArq0 = 0;
    int addArq1 = 0;
    int addArq2 = 0;
    int addArq3 = 0;
    int addArq4 = 0;
    int addArq5 = 0;
    int addArq6 = 0;

    for (int i = 0; i < tamanho; i++)
    {
        fseek(arq, i * sizeof(TFunc), SEEK_SET);
        RRN = ftell(arq);
        TFunc func = readFile(arq, i);
        int mod = func.code % 7;
        inserirFim(&lista[mod], func.code, RRN);

        switch (mod)
        {
        case 0:
            createArqByOne(func, arq0, addArq0);

            // TFunc funcTeste = readFile(arq0, addArq0);
            // leFunc(funcTeste);
            // printf("\n");

            addArq0 = addArq0 + 1;
            break;
        case 1:
            createArqByOne(func, arq1, addArq1);

            // TFunc funcTeste = readFile(arq1, addArq1);
            // leFunc(funcTeste);

            addArq1 = addArq1 + 1;
            break;
        case 2:
            createArqByOne(func, arq2, addArq2);

            // TFunc funcTeste = readFile(arq2, addArq2);
            // leFunc(funcTeste);

            addArq2 = addArq2 + 1;
            break;
        case 3:
            createArqByOne(func, arq3, addArq3);

            // TFunc funcTeste = readFile(arq3, addArq3);
            // leFunc(funcTeste);

            addArq3 = addArq3 + 1;
            break;
        case 4:
            createArqByOne(func, arq4, addArq4);

            // TFunc funcTeste = readFile(arq4, addArq4);
            // leFunc(funcTeste);

            addArq4 = addArq4 + 1;
            break;
        case 5:
            createArqByOne(func, arq5, addArq5);

            // TFunc funcTeste = readFile(arq5, addArq5);
            // leFunc(funcTeste);

            addArq5 = addArq5 + 1;
            break;
        case 6:
            createArqByOne(func, arq6, addArq6);

            // TFunc funcTeste = readFile(arq6, addArq6);
            // leFunc(funcTeste);

            addArq6 = addArq6 + 1;
            break;
        }
    }

    // funcao para testar
    // for (int i = 0; i < 7; i++)
    // {
    //     printf("Gaveta %i = ", i);
    //     imprimir(&lista[i]);
    // }

    printf("Gaveta 0 = ");
    imprimir(&lista[0]);
    printf("\n\nArquivo organizado com sucesso!\n\n");
}
