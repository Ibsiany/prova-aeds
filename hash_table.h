#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "prova1.h"

typedef struct
{
    Key_Sorting func[7];
    int tamanho;
} THash;

void init(THash *hash, int n);
void insert_hash(THash *hash, Key_Sorting item, int n);
void to_string_hash(THash *hash, int n);