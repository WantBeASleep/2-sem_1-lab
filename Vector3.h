//structs
struct RingInfo;
struct Vector3;

//funcs

struct ringInfo* Create(
    void* zero,
    void* one,
    void* (*module)(struct Vector3*),
    void* (*sum)(void*, void*),
    void* (*minus)(void*, void*),
    void* (*scalar)(struct Vector3*, struct Vector3*));

//Vector create

struct Vector3* Zero(struct ringInfo*);
struct Vector3* E_1(struct ringInfo*);
struct Vector3* E_2(struct ringInfo*);
struct Vector3* E_3(struct ringInfo*);
// struct Vector3* VectorFrom(struct ringInfo*, void*);

//decomposition

void* GetX(struct Vector3*);
void* GetY(struct Vector3*);
void* GetZ(struct Vector3*);

//unar operation block

void* VectorModule(struct Vector3*);

//binar operation block

struct Vector3* Sum(struct Vector3*, struct Vector3*);
struct Vector3* Minus(struct Vector3*, struct Vector3*);
void* Scalar(struct Vector3*, struct Vector3*);
