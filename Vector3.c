#include "Vector3.h"

#include <stdlib.h>
#include <math.h>
#include <stdio.h>


// date block
struct ringInfo
{
    void* zero;
    void* one;
    void* (*module)(struct Vector3*);
    void* (*sum)(void*, void*);
    void* (*minus)(void*, void*);
    void* (*scalar)(struct Vector3*, struct Vector3*);
};

struct Vector3
{
    struct ringInfo* ringInfo;
    void *x;
    void *y;
    void *z;
};

//func

struct ringInfo* Create(
    void* zero,
    void* one,
    void* (*module)(struct Vector3*),
    void* (*sum)(void*, void*),
    void* (*minus)(void*, void*),
    void* (*scalar)(struct Vector3*, struct Vector3*))
{
    struct ringInfo* ringInfo = (struct ringInfo*)malloc(sizeof(struct ringInfo));
    ringInfo->zero = zero;
    ringInfo->one = one;
    ringInfo->module = module;
    ringInfo->sum = sum;
    ringInfo->minus = minus;
    ringInfo->scalar = scalar;

    return ringInfo;
}

//Create block
struct Vector3* vector_zero;

struct Vector3* Zero(struct ringInfo* ringInfo)
{
    if (vector_zero) return vector_zero;

    vector_zero = (struct Vector3*)malloc(sizeof(struct Vector3));
    vector_zero->ringInfo = ringInfo;
    vector_zero->x = ringInfo->zero;
    vector_zero->y = ringInfo->zero;
    vector_zero->z = ringInfo->zero;

    return vector_zero;
}

struct Vector3* E_1(struct ringInfo* ringInfo)
{
    struct Vector3* vector = (struct Vector3*)malloc(sizeof(struct Vector3));
    vector->ringInfo = ringInfo;
    vector->x = ringInfo->one;
    vector->y = ringInfo->zero;
    vector->z = ringInfo->zero;

    return vector;
}

struct Vector3* E_2(struct ringInfo* ringInfo)
{
    struct Vector3* vector = (struct Vector3*)malloc(sizeof(struct Vector3));
    vector->ringInfo = ringInfo;
    vector->x = ringInfo->zero;
    vector->y = ringInfo->one;
    vector->z = ringInfo->zero;

    return vector;
}

struct Vector3* E_3(struct ringInfo* ringInfo)
{
    struct Vector3* vector = (struct Vector3*)malloc(sizeof(struct Vector3));
    vector->ringInfo = ringInfo;
    vector->x = ringInfo->zero;
    vector->y = ringInfo->zero;
    vector->z = ringInfo->one;

    return vector;
}

/*??? 
в любом случае нужно брать из массива данные и преобразовывать их,
преобразовывать явно, значит нужны типы и на войд`ах ничего не выйдет 
- тупик одним словом

если вкратце:
приходит значение int/float - не ебет
создаем указатель этого типа, значение вписываем из массива
передаем в структуру этот указатль преобразованный в void

очев решение - изначально хранить массив в указателях - ебанизм и онанизм,
и если второе мы поддерживаем, то первого мне хватает на
*/
// struct Vector3* VectorFrom(struct ringInfo* ringInfo, void* values)
// {
    
// }

//decomposition
void* GetX(struct Vector3* vector)
{
    return vector->x;
}

void* GetY(struct Vector3* vector)
{
    return vector->x;
}

void* GetZ(struct Vector3* vector)
{
    return vector->x;
}

//unar operation block
void* VectorModule(struct Vector3* vector)
{
    return vector->ringInfo->module(vector);
}

//binar operation block
struct Vector3* Sum(struct Vector3* v1, struct Vector3* v2)
{
    struct Vector3* result = (struct Vector3 *)malloc(sizeof(struct Vector3));
    result->ringInfo = v1->ringInfo;
    result->x = result->ringInfo->sum(v1->x, v2->x);
    result->y = result->ringInfo->sum(v1->y, v2->y);
    result->z = result->ringInfo->sum(v1->z, v2->z);

    return result;
}

struct Vector3* Minus(struct Vector3* v1, struct Vector3* v2)
{
    struct Vector3* result = (struct Vector3 *)malloc(sizeof(struct Vector3));
    result->ringInfo = v1->ringInfo;
    result->x = result->ringInfo->minus(v1->x, v2->x);
    result->y = result->ringInfo->minus(v1->y, v2->y);
    result->z = result->ringInfo->minus(v1->z, v2->z);

    return result;
}

void* Scalar(struct Vector3* v1, struct Vector3* v2)
{
    return v1->ringInfo->scalar(v1, v2);
}
