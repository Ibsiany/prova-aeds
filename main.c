#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "./hash_table.h"
#include "./lista.h"

int n = 100;

// Gustavo Tadeu Alves do Couto 20.2.8124
// Ibsiany Dias Godinho 20.2.8097
// repo: https://github.com/Ibsiany/prova-aeds

typedef struct Select
{
    int code;
    TFunc func;
    int freeze;
} TSelect;

int menorIndex(TSelect vet[])
{
    int index = 0;
    int aux = 999;
    for (int i = 0; i <= 6; i++)
    {
        if (vet[i].code <= aux && vet[i].freeze == 0)
        {
            aux = vet[i].code;
            index = i;
        }
    }
    return index;
}

void descongela(TSelect vet[])
{
    for (int i = 0; i <= 6; i++)
    {
        vet[i].freeze = 0;
    }
}

void selecaoSubs(FILE *arq, FILE *arq1, FILE *arq2, FILE *arq3, FILE *arq4, FILE *arq5, FILE *arq6, FILE *arq7, FILE *arq8, FILE *arq9, int particao, int *u)
{
    printf("\nParticao %i criada com sucesso\n", particao);
    arq = fopen("binario.dat", "rb");

    TSelect vet[6];
    int freeze = 0;
    int v = 0;
    int menor;
    int count = 0;
    while (freeze != 6)
    {
        TFunc func = readFile(arq, *u);
        vet[v].code = func.code;
        vet[v].func = func;
        vet[v].freeze = 0;
        v++;
        *u = *u + 1;
        freeze++;
    }
    v = 0;
    while (freeze != 0)
    {
        menor = menorIndex(vet);
        TFunc proximo = readFile(arq, *u);

        createArqByOne(vet[menor].func, arq1, v);
        count++;
        if (vet[menor].code < proximo.code)
        {
            vet[menor].code = proximo.code;
            vet[menor].func = proximo;
            vet[menor].freeze = 0;
        }
        else
        {
            vet[menor].freeze = 1;
            vet[menor].code = proximo.code;
            vet[menor].func = proximo;
            freeze--;
        }
        v++;
        *u = *u + 1;
    }

    freeze = 0;
    fclose(arq1);
    particao++;

    // Parte 2 do codigo

    printf("\nParticao %i criada com sucesso\n", particao);
    freeze = 6;
    descongela(vet);
    v = 0;
    while (freeze != 0)
    {
        menor = menorIndex(vet);
        TFunc proximo = readFile(arq, *u);

        createArqByOne(vet[menor].func, arq2, v);
        count++;
        if (vet[menor].code < proximo.code)
        {
            vet[menor].code = proximo.code;
            vet[menor].func = proximo;
            vet[menor].freeze = 0;
        }
        else
        {
            vet[menor].freeze = 1;
            vet[menor].code = proximo.code;
            vet[menor].func = proximo;
            freeze--;
        }

        v++;
        *u = *u + 1;
    }

    freeze = 0;

    fclose(arq2);
    particao++;

    // Parte 3 do codigo

    printf("\nParticao %i criada com sucesso\n", particao);
    freeze = 6;
    descongela(vet);
    v = 0;
    while (freeze != 0)
    {
        menor = menorIndex(vet);
        TFunc proximo = readFile(arq, *u);

        createArqByOne(vet[menor].func, arq3, v);
        count++;

        if (vet[menor].code < proximo.code)
        {
            vet[menor].code = proximo.code;
            vet[menor].func = proximo;
            vet[menor].freeze = 0;
        }
        else
        {
            vet[menor].freeze = 1;
            vet[menor].code = proximo.code;
            vet[menor].func = proximo;
            freeze--;
        }
        v++;
        *u = *u + 1;
    }

    freeze = 0;

    fclose(arq3);
    particao++;

    // Parte 4 do codigo

    printf("\nParticao %i criada com sucesso\n", particao);
    freeze = 6;
    descongela(vet);
    v = 0;
    while (freeze != 0)
    {
        menor = menorIndex(vet);
        TFunc proximo = readFile(arq, *u);

        createArqByOne(vet[menor].func, arq4, v);
        count++;

        if (vet[menor].code < proximo.code)
        {
            vet[menor].code = proximo.code;
            vet[menor].func = proximo;
            vet[menor].freeze = 0;
        }
        else
        {
            vet[menor].freeze = 1;
            vet[menor].code = proximo.code;
            vet[menor].func = proximo;
            freeze--;
        }

        v++;
        *u = *u + 1;
    }

    freeze = 0;

    fclose(arq4);
    particao++;

    // Parte 5 do codigo

    printf("\nParticao %i criada com sucesso\n", particao);
    freeze = 6;
    descongela(vet);
    v = 0;
    while (freeze != 0)
    {
        menor = menorIndex(vet);
        TFunc proximo = readFile(arq, *u);

        createArqByOne(vet[menor].func, arq5, v);
        count++;

        if (vet[menor].code < proximo.code)
        {
            vet[menor].code = proximo.code;
            vet[menor].func = proximo;
            vet[menor].freeze = 0;
        }
        else
        {
            vet[menor].freeze = 1;
            vet[menor].code = proximo.code;
            vet[menor].func = proximo;
            freeze--;
        }

        v++;
        *u = *u + 1;
    }

    freeze = 0;

    fclose(arq5);
    particao++;

    // Parte 6 do codigo

    printf("\nParticao %i criada com sucesso\n", particao);
    freeze = 6;
    descongela(vet);
    v = 0;
    while (freeze != 0)
    {
        menor = menorIndex(vet);
        TFunc proximo = readFile(arq, *u);

        createArqByOne(vet[menor].func, arq6, v);
        count++;

        if (vet[menor].code < proximo.code)
        {
            vet[menor].code = proximo.code;
            vet[menor].func = proximo;
            vet[menor].freeze = 0;
        }
        else
        {
            vet[menor].freeze = 1;
            vet[menor].code = proximo.code;
            vet[menor].func = proximo;
            freeze--;
        }

        v++;
        *u = *u + 1;
    }

    freeze = 0;

    fclose(arq6);
    particao++;

    // Parte 7 do codigo

    printf("\nParticao %i criada com sucesso\n", particao);
    freeze = 6;
    descongela(vet);
    v = 0;
    while (freeze != 0)
    {
        menor = menorIndex(vet);
        TFunc proximo = readFile(arq, *u);

        createArqByOne(vet[menor].func, arq7, v);
        count++;

        if (vet[menor].code < proximo.code)
        {
            vet[menor].code = proximo.code;
            vet[menor].func = proximo;
            vet[menor].freeze = 0;
        }
        else
        {
            vet[menor].freeze = 1;
            vet[menor].code = proximo.code;
            vet[menor].func = proximo;
            freeze--;
        }

        v++;
        *u = *u + 1;
    }

    freeze = 0;
    fclose(arq7);
    particao++;

    // Parte 8 do codigo

    printf("\nParticao %i criada com sucesso\n", particao);
    freeze = 6;
    descongela(vet);
    v = 0;
    while (freeze != 0)
    {
        menor = menorIndex(vet);
        TFunc proximo = readFile(arq, *u);

        createArqByOne(vet[menor].func, arq8, v);
        count++;

        if (vet[menor].code < proximo.code)
        {
            vet[menor].code = proximo.code;
            vet[menor].func = proximo;
            vet[menor].freeze = 0;
        }
        else
        {
            vet[menor].freeze = 1;
            vet[menor].code = proximo.code;
            vet[menor].func = proximo;
            freeze--;
        }
        v++;
        *u = *u + 1;
    }

    freeze = 0;

    fclose(arq8);
    particao++;

    // Parte 9 do codigo

    printf("\nParticao %i criada com sucesso\n", particao);
    freeze = 6;
    descongela(vet);
    v = 0;
    while (freeze != 0)
    {
        menor = menorIndex(vet);
        TFunc proximo = readFile(arq, *u);

        createArqByOne(vet[menor].func, arq9, v);
        count++;
        if (count == 101)
        {
            break;
        }
        if (vet[menor].code < proximo.code)
        {
            vet[menor].code = proximo.code;
            vet[menor].func = proximo;
            vet[menor].freeze = 0;
        }
        else
        {
            vet[menor].freeze = 1;
            vet[menor].code = proximo.code;
            vet[menor].func = proximo;
            freeze--;
        }

        v++;
        *u = *u + 1;
    }

    freeze = 0;
    fclose(arq9);
    particao++;
}

void select_busca(FILE *arq, FILE *ordenado, int n)
{
    int valorBusca = 0;
    int order = 0;
    int busca = 0;

    printf("Informe qual busca deseja realizar:\n1.Sequencial\n2.Binaria\n3.Voltar\n- ");
    scanf("%d", &busca);

    switch (busca)
    {
    case 1:
        printf("Informe um valor de 0 a 99:\n- ");
        scanf("%d", &valorBusca);
        sequencial(valorBusca, arq, n);
        break;
    case 2:
        printf("Informe um valor de 0 a 99:\n- ");
        scanf("%d", &valorBusca);

        printf("De qual forma deseja ordenar o arquivo?\n1.Key sorting\n2.Insertion sort\n3.Voltar\n- ");
        scanf("%d", &order);

        arq = fopen("binario.dat", "rb");
        ordenado = fopen("binario_ordenado.dat", "rb+");
        switch (order)
        {
        case 1:
            keySorting(arq, ordenado, n);
            break;
        case 2:
            insertionSort(ordenado, n);
            break;
        case 3:
            // system("cls");

            return;
        default:
            printf("Valor invalido.");

            select_busca(arq, ordenado, n);
            break;
        }

        fclose(arq);
        fclose(ordenado);

        busca_binaria(valorBusca, ordenado, n);

        break;
    case 3:
        return;
    default:
        printf("Valor invalido.");
        select_busca(arq, ordenado, n);
        break;
    }
}

void hash_table(THash *hash)
{
    int hash_select = 0;
    int hash_metodo = 0;

    FILE *arq = fopen("binario.dat", "rb+");

    TFunc *func = (TFunc *)malloc(sizeof(TFunc));

    Key_Sorting *key = (Key_Sorting *)malloc(sizeof(Key_Sorting));

    printf("Informe qual hash deseja realizar:\n1.Sem tratamento\n2.Com tratamento\n- ");
    scanf("%d", &hash_select);

    switch (hash_select)
    {
    case 1:
        printf("Escolha uma opcao:\n1.Insercao\n2.Visualizacao \n- ");
        scanf("%d", &hash_metodo);

        switch (hash_metodo)
        {
        case 1:

            fflush(stdin);
            printf("\nInforme o code: ");
            scanf("%d", &func->code);

            key->code = func->code;
            key->RRN = n * sizeof(TFunc);

            fflush(stdin);
            printf("\nInforme o nome: ");
            fgets(func->nome, 300, stdin);

            fflush(stdin);
            printf("\nInforme o nascimento: ");
            fgets(func->data_nascimento, 300, stdin);

            fflush(stdin);
            printf("\nInforme o salario: ");
            scanf("%d", &func->salario);

            createArqByOne(*func, arq, n);

            insert_hash(hash, *key, 7);

            n = n + 1;

            break;
        case 2:
            to_string_hash(hash, 7);
            break;
        default:
            printf("Valor invalido.");
            break;
        }
        break;
    case 2:
        create_many_withTreatment(arq, 100);
        break;
    default:
        printf("Valor invalido.");
        break;
    }

    fclose(arq);
}

void main()
{
    double time_spent = 0.0;

    clock_t begin = clock();
    int u = 0, particao = 1;

    FILE *arq = fopen("binario.dat", "w+b");

    FILE *arq7 = fopen("0.dat", "w+b");
    FILE *arq1 = fopen("1.dat", "w+b");
    FILE *arq2 = fopen("2.dat", "w+b");
    FILE *arq3 = fopen("3.dat", "w+b");
    FILE *arq4 = fopen("4.dat", "w+b");
    FILE *arq5 = fopen("5.dat", "w+b");
    FILE *arq6 = fopen("6.dat", "w+b");

    arq1 = fopen("0.dat", "r+b");
    arq2 = fopen("1.dat", "r+b");
    arq3 = fopen("2.dat", "r+b");
    arq4 = fopen("3.dat", "r+b");
    arq5 = fopen("4.dat", "r+b");
    arq6 = fopen("5.dat", "r+b");
    arq7 = fopen("6.dat", "r+b");

    FILE *ordenado = fopen("binario_ordenado.dat", "wb"), *arq_file = fopen("binario_arvore_b.dat", "wb");

    TFunc *funcs = (TFunc *)malloc(sizeof(TFunc));

    funcs = (TFunc *)realloc(funcs, n * sizeof(TFunc));

    createFunc(funcs, n);

    createArq(funcs, arq, n);

    THash *hash = (THash *)malloc(sizeof(THash));

    init(hash, 7);
    create_many(hash, funcs, 7, n);
    int valid = 1;

    while (valid == 1)
    {
        int metodo = 0;

        printf("Informe qual metodo deseja realizar:\n1.Busca\n2.Arvore\n3.Gerar particoes com Selecao Natural\n4.Hash\n- ");
        scanf("%d", &metodo);

        switch (metodo)
        {
        case 1:
            select_busca(arq, ordenado, n);

            break;
        case 2:
            break;
        case 3:
            // selecaoSubs(arq, arq1, arq2, arq3, arq4, arq5, arq6, arq7, arq8, arq9, particao, &u);
            break;
        case 4:
            hash_table(hash);
            break;
        default:
            printf("Valor invalido.");
            break;
        }

        printf("\n\nDeseja realizar outra operacao?\n1.Sim\n2.Nao\n- ");
        scanf("%d", &valid);
    }

    free(funcs);

    clock_t end = clock();

    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\nTempo de processamento do programa: %.2f", time_spent);
}
