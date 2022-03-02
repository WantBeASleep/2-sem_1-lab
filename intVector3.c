// void *sumInt(void *a1, void *a2)
// {
//     int *ia1 = (int *)a1;
//     int *ia2 = (int *)a2;
    
//     int *res = (int *)malloc(sizeof(int));
//     *res = *ia1 + *ia2;

//     return (void *)res;
// }

// void *scalarInt(struct Vector3 *v1, struct Vector3 *v2)
// {
//     struct Vector3 *iV1 = (struct Vector3 *)v1;
//     struct Vector3 *iV2 = (struct Vector3 *)v2;

//     int *res = (int *)malloc(sizeof(int));
//     *res = 0;
//     *res += *(int *)(iV1->x) * *(int *)(iV2->x);
//     *res += *(int *)(iV1->y) * *(int *)(iV2->y);
//     *res += *(int *)(iV1->z) * *(int *)(iV2->z);

//     return (void *)res;
// }
