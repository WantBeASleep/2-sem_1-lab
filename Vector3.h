#include <string.h>

//structs
struct RingInfo;
struct Vector3;

//funcs

struct RingInfo* Create(
    size_t size,
    void* zero,
    void* one,
    void* (*sum)(void*, void*),
    void* (*minus)(void*, void*),
    void* (*scalar)(void**, void**));

//Vector create

struct Vector3* Zero(struct RingInfo*);
struct Vector3* E_1(struct RingInfo*);
struct Vector3* E_2(struct RingInfo*);
struct Vector3* E_3(struct RingInfo*);
struct Vector3* VectorFrom(struct RingInfo*, void**);

//decomposition

void* GetX(struct Vector3*);
void* GetY(struct Vector3*);
void* GetZ(struct Vector3*);

//binar operation block

struct Vector3* Sum(struct Vector3*, struct Vector3*);
struct Vector3* Minus(struct Vector3*, struct Vector3*);
void* Scalar(struct Vector3*, struct Vector3*);
