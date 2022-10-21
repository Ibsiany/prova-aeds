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
    printf("Gaveta x = [Codigo, Endereco]\n\n");
    arq = fopen("binario.dat", "rb");
    Lista lista [7];
    rewind(arq);
    long RRN;

    //Iniciando as listas

    for (int i = 0; i<7; i++){
        lista[i].inicio = NULL;
        lista[i].fim = NULL;
        lista[i].tam = 0;
    }

    //Utilizando o Hash

        for (int i = 0; i < tamanho; i++)
    {
        fseek(arq, i * sizeof(TFunc), SEEK_SET);
        RRN = ftell(arq);
        TFunc func = readFile(arq, i);
        int mod = func.code%7;
        inserirFim(&lista[mod], func.code, RRN);
    }
    for (int i = 0; i<7; i++){
            printf("Gaveta %i = ", i);
        imprimir(&lista[i]);
    }
}
