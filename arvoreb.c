#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./arvoreb.h"

Node *criaNo(Key_Sorting *x)
{
    Node *novo_no = (Node *)malloc(sizeof(Node));
    novo_no->key = (Key_Sorting *)malloc(sizeof(Key_Sorting));
    novo_no->key->code = x->code;
    novo_no->key->RRN = x->RRN;
    novo_no->left = NULL;
    novo_no->right = NULL;
    return (novo_no);
};

int insert(Node **ppRaiz, Key_Sorting *x, int n, TFunc *func)
{
    if (*ppRaiz == NULL)
    {
        FILE *arq_file = fopen("binario_arvore_b.dat", "rb+");

        createArqByOne(*func, arq_file, n);

        fclose(arq_file);

        *ppRaiz = criaNo(x);

        return 1;
    }
    if (x->code < (*ppRaiz)->key->code)
        return insert(&((*ppRaiz)->left), x, n, func);
    if (x->code > (*ppRaiz)->key->code)
        return insert(&((*ppRaiz)->right), x, n, func);
    return 0;
};

void createFuncWithTree(TFunc *funcs, Node **no, int n)
{
    Key_Sorting *key = (Key_Sorting *)malloc(sizeof(Key_Sorting));

    for (int j = 0; j < n; j++)
    {
        key->code = funcs[j].code;
        key->RRN = j;
        insert(no, key, j, &funcs[j]);
    }
}

int search(Node *no, int code)
{
    if (no == NULL)
    {
        printf("Arvore nula!");

        return 0;
    }
    else if (code < no->key->code)
    {
        return search(no->left, code);
    }
    else if (code > no->key->code)
    {
        return search(no->right, code);
    }
    else
    {
        printf("\nCodigo %d encontrado no indice %d!\n\n", no->key->code, no->key->RRN);

        printf("\n********* INFORMACOES DO FUNCIONARIO %d ENCONTRADO ********* !\n\n", no->key->code);

        FILE *arq_file = fopen("binario_arvore_b.dat", "rb+");

        TFunc func = readFile(arq_file, no->key->RRN);

        leFunc(func);

        fclose(arq_file);

        return 1;
    }
}

void toString(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        toString(root->left);
        printf("\nCode: %d\n", root->key->code);
        printf("Indice: %d\n", root->key->RRN);
        toString(root->right);
    }
}

void remove_tree(Node *root, int id)
{
    Node *prox = NULL;

    Node *atual = root;

    while (atual != NULL)
    {
        if (atual->key->code == id)
        {
            if (atual->left == NULL && atual->right == NULL)
            {
                if (prox == NULL)
                {
                    root = NULL;
                }
                else
                {
                    if (prox->left == atual)
                    {
                        prox->left = NULL;
                    }
                    else
                    {
                        prox->right = NULL;
                    }
                }
            }
            else if (atual->left == NULL)
            {
                if (prox == NULL)
                {
                    root = atual->right;
                }
                else
                {
                    if (prox->left == atual)
                    {
                        prox->left = atual->right;
                    }
                    else
                    {
                        prox->right = atual->right;
                    }
                }
            }
            else if (atual->right == NULL)
            {
                if (prox == NULL)
                {
                    root = atual->left;
                }
                else
                {
                    if (prox->left == atual)
                    {
                        prox->left = atual->left;
                    }
                    else
                    {
                        prox->right = atual->left;
                    }
                }
            }
            else
            {
                Node *successor = atual->right;

                Node *successor_parent = atual;

                while (successor->left != NULL)
                {
                    successor_parent = successor;
                    successor = successor->left;
                }

                if (successor_parent->left == successor)
                {
                    successor_parent->left = successor->right;
                }
                else
                {
                    successor_parent->right = successor->right;
                }

                atual->key = successor->key;
            }

            free(atual);

            return;
        }
        else if (atual->key->code > id)
        {
            prox = atual;
            atual = atual->left;
        }
        else
        {
            prox = atual;
            atual = atual->right;
        }
    }
}