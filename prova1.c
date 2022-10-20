#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "./prova1.h"

void leFunc(TFunc funcs)
{
    printf("Nome: %s\n", funcs.nome);
    printf("Nascimento: %s\n", funcs.data_nascimento);
    printf("Codigo: %d\n", funcs.code);
    printf("Salario: %d\n", funcs.salario);
}

void createFunc(TFunc *funcs, int n)
{
    int array[100] = {73, 1, 6, 84, 14, 87, 32, 38, 4, 85, 2, 54, 5, 92, 42,
                      72, 71, 65, 49, 66, 31, 79, 23, 74, 48, 95, 97, 67, 83, 13,
                      59, 57, 44, 37, 26, 86, 29, 25, 7, 80, 17, 40, 24, 10, 82,
                      62, 98, 88, 75, 39, 11, 47, 94, 30, 90, 34, 89, 81, 19, 45,
                      46, 28, 27, 18, 15, 78, 77, 58, 12, 36, 69, 60, 51, 68, 43,
                      20, 22, 52, 3, 55, 21, 64, 63, 41, 99, 0, 35, 16, 96, 70,
                      91, 93, 53, 9, 33, 61, 50, 56, 8, 76};

    for (int j = 0; j < n; j++)
    {
        funcs[j].code = array[j];
        sprintf(funcs[j].nome, "Funcionario N%d", array[j]);
        funcs[j].salario = j + 1 * 1000;
        strcpy(funcs[j].data_nascimento, "14/06/2000");
    }
}

void createArq(TFunc *funcs, FILE *arq, int n)
{
    if (arq != NULL)
    {
        for (int i = 0; i < n; i++)
        {
            fseek(arq, (i) * sizeof(TFunc), SEEK_SET);
            fwrite(&funcs[i], sizeof(TFunc), 1, arq);
        }
    }

    fclose(arq);
}

void createArqByOne(TFunc func, FILE *ordenado, int i)
{
    if (ordenado != NULL)
    {
        fseek(ordenado, (i) * sizeof(TFunc), SEEK_SET);
        fwrite(&func, sizeof(TFunc), 1, ordenado);
    }
}

TFunc readFile(FILE *arq, int i)
{
    TFunc func;

    fseek(arq, i * sizeof(TFunc), SEEK_SET);
    fread(&func, sizeof(TFunc), 1, arq);

    return func;
}

TFunc readFileWithByte(FILE *arq)
{
    TFunc func;

    fread(&func, sizeof(TFunc), 1, arq);

    return func;
}

void sequencial(int code, FILE *arq, int tamanho)
{
    double time_spent = 0.0;

    clock_t begin = clock();

    int tentativas = 0;

    arq = fopen("binario.dat", "rb");

    for (int i = 0; i < tamanho; i++)
    {

        TFunc func = readFile(arq, i);

        if (func.code == code)
        {
            fclose(arq);

            printf("\n********** Busca sequencial: Funcionario encontrado "
                   "**********\nTentativas realizadas: %d\n",
                   tentativas);

            leFunc(func);

            clock_t end = clock();

            time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

            printf("Tempo de processamento da busca sequencial: %.2f", time_spent);

            return;
        }

        tentativas = tentativas + 1;
    }

    printf("\n#### Funcionario NAO encontrado ####\n\n");

    clock_t end = clock();

    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Tempo de processamento da busca sequencial: %.2f", time_spent);

    fclose(arq);
}

void busca_binaria(int code, FILE *arq, int tam)
{
    arq = fopen("binario_ordenado.dat", "rb");

    double time_spent = 0.0;

    clock_t begin = clock();

    int left = 0, right = tam - 1, i = 0;

    int tentativas = 0;

    while (left <= right)
    {

        int middle = (left + right) / 2;

        TFunc func = readFile(arq, middle);

        i = i + 1;

        if (code == func.code)
        {
            printf("\n\n********** Busca binaria: Funcionario encontrado "
                   "\n********** Tentativas realizadas: %d\n",
                   tentativas);

            leFunc(func);

            clock_t end = clock();

            time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

            fclose(arq);

            printf("Tempo de processamento da busca binaria: %.2f\n", time_spent);

            return;
        }
        else if (func.code < code)
        {
            tentativas++;
            left = middle + 1;
        }
        else
        {
            tentativas++;
            right = middle - 1;
        }
    }

    printf("Ocorreu um erro ao realizar busca!\n");

    fclose(arq);
}

void keySorting(FILE *arq, FILE *ordenado, int tamanho)
{
    double time_spent = 0.0;

    clock_t begin = clock();

    Key_Sorting array[tamanho];

    rewind(arq);

    for (int i = 0; i < tamanho; i++)
    {
        fseek(arq, i * sizeof(TFunc), SEEK_SET);
        array[i].RRN = ftell(arq);
        TFunc func = readFile(arq, i);
        array[i].code = func.code;
    }

    for (int i = 0; i < tamanho; i++)
    {
        for (int j = i + 1; j < tamanho; j++)
        {
            if (array[i].code > array[j].code)
            {
                Key_Sorting aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
    }

    rewind(arq);

    for (int i = 0; i < tamanho; i++)
    {
        fseek(arq, array[i].RRN, SEEK_SET);
        TFunc func = readFileWithByte(arq);

        createArqByOne(func, ordenado, i);
    }

    clock_t end = clock();

    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\nTempo de processamento do key sorting: %.2f\n\n", time_spent);

    fclose(arq);
}

void insertionSort(FILE *ordenado, int tamanho)
{
    double time_spent = 0.0;

    clock_t begin = clock();

    rewind(ordenado);

    int i;
    for (int j = 2; j <= tamanho; j++)
    {
        TFunc funcJ = readFile(ordenado, j - 1);
        i = j - 1;

        TFunc funcI = readFile(ordenado, i - 1);
        while ((i > 0) && (funcI.code > funcJ.code))
        {
            createArqByOne(funcI, ordenado, i);
            i = i - 1;

            funcI = readFile(ordenado, i - 1);
        }
        createArqByOne(funcJ, ordenado, i);
    }

    fflush(ordenado);

    fclose(ordenado);

    clock_t end = clock();

    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\nTempo de processamento do insertion sort: %.2f\n\n", time_spent);
}

