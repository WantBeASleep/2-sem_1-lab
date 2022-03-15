#include "Vector3.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//ringinfo buddy
size_t sizeDouble;
double* zeroDouble;
double* oneDouble;

void doubleConst()
{
    sizeDouble = sizeof(double*);
    zeroDouble = (double*)malloc(sizeof(double));
    oneDouble = (double*)malloc(sizeof(double));

    *zeroDouble = 0.0;
    *oneDouble = 1.0;

    return;
}

void *sumDouble(void *a1, void *a2)
{
    double *ia1 = (double *)a1;
    double *ia2 = (double *)a2;
    
    double *res = (double *)malloc(sizeof(double));
    *res = *ia1 + *ia2;

    return (void*)res;
}

void *minusDouble(void *a1, void *a2)
{
    double* ia1 = (double *)a1;
    double* ia2 = (double *)a2;
    
    double* res = (double *)malloc(sizeof(double));
    *res = *ia1 - *ia2;

    return (void*)res;
}

void *scalarDouble(void **v1_values, void **v2_values)
{
    double *res = (double*)malloc(sizeof(double));
    *res = 0;
    for (int i=0; i<3; i++)
    {
        *res += *(double*)(v1_values[i]) * *(double*)(v2_values[i]);
    }

    return (void*)res;
}

void **DoubleTests()
{
    double *x, *y, *z;
    x = (double*)malloc(sizeof(double));
    y = (double*)malloc(sizeof(double));
    z = (double*)malloc(sizeof(double));

    *x = 1.0;
    *y = 2.0;
    *z = 3.0;

    void **testValue = (void**)malloc(sizeof(double*));
    testValue[0] = (void*)x;
    testValue[1] = (void*)y;
    testValue[2] = (void*)z;

    return testValue;
}

void **DoubleParse()
{
    double *x, *y, *z;
    x = (double*)malloc(sizeof(double));
    y = (double*)malloc(sizeof(double));
    z = (double*)malloc(sizeof(double));

    printf("Enter 3 components: ");
    scanf("%lf %lf %lf", x, y, z);

    void **parsedValues = (void**)malloc(sizeof(double*));
    parsedValues[0] = (void*)x;
    parsedValues[1] = (void*)y;
    parsedValues[2] = (void*)z;

    return parsedValues;
}

void DoubleOutputStream(void* number)
{
    printf("%f", *(double*)number);
}