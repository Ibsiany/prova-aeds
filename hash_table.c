#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash_table.h"

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

void to_string_hash(THash *hash, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (hash->func[i].code == -1)
        {
            printf("\n Espaco %i Vazio\n", i);

            continue;
        }

        printf("\n############## Espaco %i, Funcionario %i ##############\n", i, hash->func[i].code);
    }
}