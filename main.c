#include "Vector3.h"
#include "intVector3.h"
#include "secret.h"
#include <stdio.h>
#include <stdlib.h>

void intMenu();

int main()
{
    printf("-Type?\n\t--int: 1\n\t--float: 2\n");
    int choose;
    scanf("%d", &choose);
    if (choose == 1)
    {
        intMenu();
    } else {
        //float
    }
    return 0;
}

void intMenu()
{
    intConst(); // задать интовые 0 и 1-цы
    struct Vector3** data = (struct Vector3**)malloc(2 * sizeof(struct Vector3*));

    struct RingInfo* ringinfo;
    ringinfo = Create((void*)zeroInt, (void*)oneInt, &moduleInt, &sumInt, &minusInt, &scalarInt);

    for(;;)
    {
        printf("\t-Int Mode-\n");
        printf("-v1:\n");
        printf("\t--determinate as 0, E1, E2, E3, From Value: 0, 1, 2, 3, 4\n");
        printf("\t--GetX (5), GetY (6), GetZ (7)\n");
        printf("\t--Module(?)(8)\n");
        printf("-v2:\n");
        printf("\t--determinate as 0, E1, E2, E3, From Value: 9, 10, 11, 12, 13\n");
        printf("\t--GetX (14), GetY (15), GetZ (16)\n");
        printf("\t--Module(?)(17)\n");
        printf("-operations:\n");
        printf("\t--sum (18), minus(19), scalar(20)");
        printf("output data - 21");
        int choose;
        scanf("%d", &choose);

        switch (choose)
        {
            case 0:
            {
                data[0] = Zero(ringinfo);
                break;
            }
            case 1:
            {   
                data[0] = E_1(ringinfo);
                break;
            }
            case 2:
            {   
                data[0] = E_2(ringinfo);
                break;
            }
            case 3:
            {   
                data[0] = E_3(ringinfo);
                break;
            }
            case 4:
            {
                int values[3];
                for(int i=0; i<3; i++)
                {
                    printf("%d component - ", i);
                    scanf("%d", &(values[i]));
                }
                data[0] = VectorFromInt(ringinfo, values);
                break;
            }
            case 5:
            {
                printf("GetX(v1) - %d\n", *(int*)(GetX(data[0])));
                break;
            }
            case 6:
            {
                printf("GetX(v1) - %d\n", *(int*)(GetX(data[0])));
                break;
            }
            case 7:
            {
                printf("GetX(v1) - %d\n", *(int*)(GetX(data[0])));
                break;
            }

            case 9:
            {
                data[1] = Zero(ringinfo);
                break;
            }
            case 10:
            {   
                data[1] = E_1(ringinfo);
                break;
            }
            case 11:
            {   
                data[1] = E_2(ringinfo);
                break;
            }
            case 12:
            {   
                data[1] = E_3(ringinfo);
                break;
            }
            case 13:
            {
                int values[3];
                for(int i=0; i<3; i++)
                {
                    printf("%d component - ", i);
                    scanf("%d", &(values[i]));
                }
                data[1] = VectorFromInt(ringinfo, values);
                break;
            }
            case 14:
            {
                printf("GetX(v2) - %d\n", *(int*)(GetX(data[1])));
                break;
            }
            case 15:
            {
                printf("GetY(v2) - %d\n", *(int*)(GetY(data[1])));
                break;
            }
            case 16:
            {
                printf("GetZ(v2) - %d\n", *(int*)(GetZ(data[1])));
                break;
            }
            case 18:
            {
                OutputInt(Sum(data[0], data[1]));
                break;
            }
            case 19:
            {
                OutputInt(Minus(data[0], data[1]));
                break;
            }
            case 20:
            {
                printf("scalar(v1,v2) - %d", *(int*)Scalar(data[0], data[1]));
                break;
            }
            case 21:
            {
                printf("v1\n");
                OutputInt(data[0]);
                printf("v2\n");
                OutputInt(data[1]);
                break;
            }
            case 22:
            {
                exit(0);
                break;
            }
        }
    }

    return;
}