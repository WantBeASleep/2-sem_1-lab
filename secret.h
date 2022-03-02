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
