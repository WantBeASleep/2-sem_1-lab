#include "Vector3.h"

#include <stdlib.h>
#include <math.h>
#include <stdio.h>


// date block
struct RingInfo
{
    void* zero;
    void* one;
    void* (*sum)(void*, void*);
    void* (*minus)(void*, void*);
    // void* (*scalar)(struct Vector3*, struct Vector3*);
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
    void* (*sum)(void*, void*),
    void* (*minus)(void*, void*))
    // void* (*scalar)(struct Vector3*, struct Vector3*))
{
    struct RingInfo* ringinfo = (struct RingInfo*)malloc(sizeof(struct RingInfo));
    ringinfo->zero = zero;
    ringinfo->one = one;
    ringinfo->sum = sum;
    ringinfo->minus = minus;
    // ringinfo->scalar = scalar;

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

// void* Scalar(struct Vector3* v1, struct Vector3* v2)
// {
//     return v1->ringinfo->scalar(v1, v2);
// }
