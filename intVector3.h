struct RingInfo;
struct Vector3;

//ring
void intConst();
int* zeroInt;
int* oneInt;
void *moduleInt(struct Vector3*);
void *sumInt(void*, void*);
void *minusInt(void*, void*);
void *scalarInt(struct Vector3*, struct Vector3*);
struct Vector3* VectorFromInt(struct RingInfo*, int*);
void OutputInt(struct Vector3*);