#include "Vector3.h"
#include <stdlib.h>
#include <stdio.h>

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

// void *scalarInt(struct Vector3 *v1, struct Vector3 *v2)
// {
//     int* res = (int*)malloc(sizeof(int));
//     *res = 0;

//     int valuesV1[3] = {*(int*)(v1->x), *(int*)(v1->y), *(int*)(v1->z)};
//     int valuesV2[3] = {*(int*)(v2->x), *(int*)(v2->y), *(int*)(v2->z)};

//     for(int i=0; i<3; i++)
//     {
//         *res+= valuesV1[i] * valuesV2[i];
//     }

//     return (void*)res;
// }

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