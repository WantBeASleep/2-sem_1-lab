#include "Vector3.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>


// date block
struct RingInfo
{
    size_t size;
    void* zero;
    void* one;
    void* (*sum)(void*, void*);
    void* (*minus)(void*, void*);
    void* (*scalar)(void**, void**);
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
    size_t size,
    void* zero,
    void* one,
    void* (*sum)(void*, void*),
    void* (*minus)(void*, void*),
    void* (*scalar)(void**, void**))
{
    struct RingInfo* ringinfo = (struct RingInfo*)malloc(sizeof(struct RingInfo));
    ringinfo->size = size;
    ringinfo->zero = zero;
    ringinfo->one = one;
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

struct Vector3* VectorFrom(struct RingInfo* ringinfo, void** values)
{
    struct Vector3* vector = (struct Vector3*)malloc(sizeof(struct Vector3));
    vector->ringinfo = ringinfo;
    vector->x = values[0];
    vector->y = values[1];
    vector->z = values[2];

    return vector;
}


//decomposition
void* GetX(struct Vector3* vector)
{
    return vector->x;
}

void* GetY(struct Vector3* vector)
{
    return vector->y;
}

void* GetZ(struct Vector3* vector)
{
    return vector->z;
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
    void** v1_values = (void**)malloc(3 * sizeof(v1->ringinfo->size));
    void** v2_values = (void**)malloc(3 * sizeof(v2->ringinfo->size));

    v1_values[0] = v1->x;
    v1_values[1] = v1->y;
    v1_values[2] = v1->z;

    v2_values[0] = v2->x;
    v2_values[1] = v2->y;
    v2_values[2] = v2->z;

    return v1->ringinfo->scalar(v1_values, v2_values);
}
