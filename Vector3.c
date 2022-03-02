#include "Vector3.h"

#include <stdlib.h>
#include <math.h>
#include <stdio.h>


// date block
struct RingInfo
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
    struct RingInfo* ringinfo;
    void *x;
    void *y;
    void *z;
};

//func

struct RingInfo* Create(
    void* zero,
    void* one,
    void* (*module)(struct Vector3*),
    void* (*sum)(void*, void*),
    void* (*minus)(void*, void*),
    void* (*scalar)(struct Vector3*, struct Vector3*))
{
    struct RingInfo* ringinfo = (struct RingInfo*)malloc(sizeof(struct RingInfo));
    ringinfo->zero = zero;
    ringinfo->one = one;
    ringinfo->module = module;
    ringinfo->sum = sum;
    ringinfo->minus = minus;
    ringinfo->scalar = scalar;

    return ringinfo;
}

//Create block
struct Vector3* vector_zero;

struct Vector3* Zero(struct RingInfo* ringinfo)
{
    if (vector_zero) return vector_zero;

    vector_zero = (struct Vector3*)malloc(sizeof(struct Vector3));
    vector_zero->ringinfo = ringinfo;
    vector_zero->x = ringinfo->zero;
    vector_zero->y = ringinfo->zero;
    vector_zero->z = ringinfo->zero;

    return vector_zero;
}

struct Vector3* E_1(struct RingInfo* ringinfo)
{
    struct Vector3* vector = (struct Vector3*)malloc(sizeof(struct Vector3));
    vector->ringinfo = ringinfo;
    vector->x = ringinfo->one;
    vector->y = ringinfo->zero;
    vector->z = ringinfo->zero;

    return vector;
}

struct Vector3* E_2(struct RingInfo* ringinfo)
{
    struct Vector3* vector = (struct Vector3*)malloc(sizeof(struct Vector3));
    vector->ringinfo = ringinfo;
    vector->x = ringinfo->zero;
    vector->y = ringinfo->one;
    vector->z = ringinfo->zero;

    return vector;
}

struct Vector3* E_3(struct RingInfo* ringinfo)
{
    struct Vector3* vector = (struct Vector3*)malloc(sizeof(struct Vector3));
    vector->ringinfo = ringinfo;
    vector->x = ringinfo->zero;
    vector->y = ringinfo->zero;
    vector->z = ringinfo->one;

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
// struct Vector3* VectorFrom(struct RingInfo* ringinfo, void* values)
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
    return vector->ringinfo->module(vector);
}

//binar operation block
struct Vector3* Sum(struct Vector3* v1, struct Vector3* v2)
{
    struct Vector3* result = (struct Vector3 *)malloc(sizeof(struct Vector3));
    result->ringinfo = v1->ringinfo;
    result->x = result->ringinfo->sum(v1->x, v2->x);
    result->y = result->ringinfo->sum(v1->y, v2->y);
    result->z = result->ringinfo->sum(v1->z, v2->z);

    return result;
}

struct Vector3* Minus(struct Vector3* v1, struct Vector3* v2)
{
    struct Vector3* result = (struct Vector3 *)malloc(sizeof(struct Vector3));
    result->ringinfo = v1->ringinfo;
    result->x = result->ringinfo->minus(v1->x, v2->x);
    result->y = result->ringinfo->minus(v1->y, v2->y);
    result->z = result->ringinfo->minus(v1->z, v2->z);

    return result;
}

void* Scalar(struct Vector3* v1, struct Vector3* v2)
{
    return v1->ringinfo->scalar(v1, v2);
}
