#include "Vector3.h"
#include "secret.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//ringinfo buddy

int* zeroInt;
int* oneInt;

void intConst()
{
    zeroInt = (int*)malloc(sizeof(int));
    oneInt = (int*)malloc(sizeof(int));

    *zeroInt = 0;
    *oneInt = 1;

    return;
}

void *moduleInt(struct Vector3* vector)
{   
    int* res = malloc(sizeof(int));
    
    int x = *(int*)(vector->x);
    int y = *(int*)(vector->y);
    int z = *(int*)(vector->z);

    // *res = (int)sqrt(pow(x,2) + pow(y,2) + pow(z, 2));
    *res = 0;
    
    return (void*)res;
}

void *sumInt(void *a1, void *a2)
{
    int *ia1 = (int *)a1;
    int *ia2 = (int *)a2;
    
    int *res = (int *)malloc(sizeof(int));
    *res = *ia1 + *ia2;

    return (void*)res;
}

void *minusInt(void *a1, void *a2)
{
    int* ia1 = (int *)a1;
    int* ia2 = (int *)a2;
    
    int* res = (int *)malloc(sizeof(int));
    *res = *ia1 - *ia2;

    return (void*)res;
}

void *scalarInt(struct Vector3 *v1, struct Vector3 *v2)
{
    int* res = (int*)malloc(sizeof(int));
    *res = 0;

    int valuesV1[3] = {*(int*)(v1->x), *(int*)(v1->y), *(int*)(v1->z)};
    int valuesV2[3] = {*(int*)(v2->x), *(int*)(v2->y), *(int*)(v2->z)};

    for(int i=0; i<3; i++)
    {
        *res+= valuesV1[i] * valuesV2[i];
    }

    return (void*)res;
}

//Extra

struct Vector3* VectorFromInt(struct RingInfo* ringinfo, int* values)
{
    int* x = (int*)malloc(sizeof(int));
    int* y = (int*)malloc(sizeof(int));
    int* z = (int*)malloc(sizeof(int));

    *x = values[0];
    *y = values[1];
    *z = values[2];
    
    struct Vector3* vector = (struct Vector3*)malloc(sizeof(struct Vector3));
    vector->ringinfo = ringinfo;
    vector->x = (void*)x;
    vector->y = (void*)y;
    vector->z = (void*)z;

    return vector;
}

//int Output

void OutputInt(struct Vector3* vector)
{
    printf("-vector:\n\t--x: %d\n\t--y: %d\n\t--z: %d\n", *(int*)(vector->x), *(int*)(vector->y), *(int*)(vector->z));
    return;
}