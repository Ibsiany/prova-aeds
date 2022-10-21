#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./prova1.h"


typedef struct Node
{
    Key_Sorting *key;
    struct Node *left;
    struct Node *right;
} Node;

Node *get_root();
int search(Node *no, int index);
int insert(Node **ppRaiz, Key_Sorting *x, int n, TFunc *func);
void toString(Node *root);
void remove_tree(Node *root, int id);
void createFuncWithTree(TFunc *funcs, Node **no, int n);
