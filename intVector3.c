#include "Vector3.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//ringinfo buddy
size_t sizeInt;
int* zeroInt;
int* oneInt;

void intConst()
{
    sizeInt = sizeof(int*);
    zeroInt = (int*)malloc(sizeof(int));
    oneInt = (int*)malloc(sizeof(int));

    *zeroInt = 0;
    *oneInt = 1;

    return;
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

void *scalarInt(void **v1_values, void **v2_values)
{
    int *res = (int*)malloc(sizeof(int));
    *res = 0;
    for (int i=0; i<3; i++)
    {
        *res += *(int*)(v1_values[i]) * *(int*)(v2_values[i]);
    }

    return (void*)res;
}

void **IntParse()
{
    int *x, *y, *z;
    x = (int*)malloc(sizeof(int));
    y = (int*)malloc(sizeof(int));
    z = (int*)malloc(sizeof(int));

    printf("Enter 3 components: ");
    scanf("%d %d %d", x, y, z);

    void **parsedValues = (void**)malloc(sizeof(int*));
    parsedValues[0] = (void*)x;
    parsedValues[1] = (void*)y;
    parsedValues[2] = (void*)z;

    return parsedValues;
}

void IntOutputStream(void* number)
{
    printf("%d", *(int*)number);
}