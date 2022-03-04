#include "Vector3.h"
#include "intVector3.h"
#include "doubleVector3.h"
#include <stdlib.h>
#include <stdio.h>

void menuOperator(struct Vector3**, int);
int mainMenu();
void vectorActionsMenu(struct Vector3**, int);
void determinateMenu(struct Vector3**, int);
void GetComponentMenu(struct Vector3**, int);
void binarOperationMenu(struct Vector3**, int);
void OutPutMenu(struct Vector3**, int);

void OutPutVector(struct Vector3*);

struct RingInfo* ringinfo;
void** (*parseModule)();
void (*outputStream)(void*);
/*
для парса int или float нужно работать с типами, 
но функция по запихиванию данных в вектор должна быть универсальной,
значит делаем костыль:
struct Vector3* VectorFrom(struct RingInfo*, void**);
принимает на вход массив войд указателей на войд
а этот массив мы формируем из типов в типизированных функциях
пишем IntParse() в intVector3.c, 
создаем parsemodule который будет меняться в зависимости от типа
получаем функцию которая генерит массив void**(IntParse) и общую функцию VectorFrom.
*/


int main()
{
    printf("count of operation object?\n");
    int counter;
    scanf("%d", &counter);

    struct Vector3** data = (struct Vector3**)malloc(counter * sizeof(struct Vector3*));

    printf("-Type?\n\t--int: 1\n\t--double: 2\n");
    int choose;
    scanf("%d", &choose);
    switch (choose)
    {
        case 1:
        {
            //int
            parseModule = IntParse;
            outputStream = IntOutputStream;
            intConst();
            ringinfo = Create(sizeInt, (void*)zeroInt, (void*)oneInt, &sumInt, &minusInt, &scalarInt);
            break;
        }
        case 2:
        {
            //double
            parseModule = DoubleParse;
            outputStream = DoubleOutputStream;
            doubleConst();
            ringinfo = Create(sizeDouble, (void*)zeroDouble, (void*)oneDouble, &sumDouble, &minusDouble, &scalarDouble);
            break;
        }
        default:
        {
            return 0;
            break;
        }
    }

    menuOperator(data, counter);
    
    return 0;
}

void menuOperator(struct Vector3** data, int counter)
{
    for(;;)
    {
        int mainMenuChoose = mainMenu();
        switch (mainMenuChoose)
        {
            case 1:
            {
                vectorActionsMenu(data, counter);
                break;
            }
            case 2:
            {
                binarOperationMenu(data, counter);
                break;
            }
            case 3:
            {
                OutPutMenu(data, counter);
                break;
            }
            default:
            {
                return;
                break;
            }
        }
    }
}

int mainMenu()
{
    printf("\t-Main Menu-\n");
    printf("1) vector actions\n");
    printf("2) binar operations\n");
    printf("3) Output vector\n");
    int choose;
    scanf("%d", &choose);
    return choose;
}

void vectorActionsMenu(struct Vector3** data, int counter)
{
    printf("\t-Vector Actions Menu-\n");
    printf("1) determinate new value\n");
    printf("2) Get component\n");
    int choose;
    scanf("%d", &choose);
    switch (choose)
    {
        case 1:
        {
            determinateMenu(data, counter);
            break;
        }
        case 2:
        {
            GetComponentMenu(data, counter);
            break;
        }
        default :
        {
            return;
            break;
        }
    }
    return;
}

void determinateMenu(struct Vector3** data, int counter)
{
    printf("Enter vector number (1-%d)\n", counter);
    int vectorNumber;
    scanf("%d", &vectorNumber);
    vectorNumber--;

    printf("\t-Determinate Menu\n");
    printf("0) Zero vector\n");
    printf("1) E_1 vector\n");
    printf("2) E_2 vector\n");
    printf("3) E_3 vector\n");
    printf("4) From value vector\n");
    int determinateChoose;
    scanf("%d", &determinateChoose);
    
    switch (determinateChoose)
    {
        case 0:
        {
            data[vectorNumber] = Zero(ringinfo);
            break;
        }
        case 1:
        {
            data[vectorNumber] = E_1(ringinfo);
            break;
        }
        case 2:
        {
            data[vectorNumber] = E_2(ringinfo);
            break;
        }
        case 3:
        {
            data[vectorNumber] = E_3(ringinfo);
            break;
        }
        case 4:
        {
            data[vectorNumber] = VectorFrom(ringinfo, parseModule());
            break;
        }
        default:
        {
            return;
            break;
        }
    }
    return;
}

void GetComponentMenu(struct Vector3** data, int counter)
{
    printf("Enter vector number (1-%d)\n", counter);
    int vectorNumber;
    scanf("%d", &vectorNumber);
    vectorNumber--;

    printf("\t-Get component Menu\n");
    printf("1) Get X component\n");
    printf("2) Get Y component\n");
    printf("3) Get Z component\n");
    int componentChoose;
    scanf("%d", &componentChoose);

    switch (componentChoose)
    {
        case 1:
        {
            printf("X component of %d vector - ", vectorNumber+1);
            outputStream(GetX(data[vectorNumber]));
            printf("\n");
            break;
        }
        case 2:
        {
            printf("X component of %d vector - ", vectorNumber+1);
            outputStream(GetY(data[vectorNumber]));
            printf("\n");
            break;
        }
        case 3:
        {
            printf("X component of %d vector - ", vectorNumber+1);
            outputStream(GetZ(data[vectorNumber]));
            printf("\n");
            break;
        }
        default:
        {
            return;
            break;
        }
    }

    return;
}

void binarOperationMenu(struct Vector3** data, int counter)
{
    printf("\t-Binar Operation Menu-\n");
    printf("1) Sum vectors\n");
    printf("2) Minus vectors\n");
    printf("3) Scalar vectors\n");
    int choose;
    scanf("%d", &choose);

    switch (choose)
    {
        case 1:
        {
            printf("Enter 2 vectors numbers (1-%d)", counter);
            int v1_number, v2_number;
            scanf("%d %d", &v1_number, &v2_number);
            v1_number--;
            v2_number--;

            struct Vector3* res;
            res = Sum(data[v1_number], data[v2_number]);
            OutPutVector(res);

            printf("Save result?\n 0 - No\n Number Vector to save -");
            int saveVector;
            scanf("%d", &saveVector);
            if (!saveVector) break;
            saveVector--;
            data[saveVector] = res;

            break;
        }
        case 2:
        {
            printf("Enter 2 vectors numbers (1-%d)", counter);
            int v1_number, v2_number;
            scanf("%d %d", &v1_number, &v2_number);
            v1_number--;
            v2_number--;

            struct Vector3* res;
            res = Minus(data[v1_number], data[v2_number]);
            OutPutVector(res);

            printf("Save result?\n 0 - No\n Number Vector to save -");
            int saveVector;
            scanf("%d", &saveVector);
            if (!saveVector) break;
            saveVector--;
            data[saveVector] = res;
            
            break;
        }
        case 3:
        {
            printf("Enter 2 vectors numbers (1-%d)", counter);
            int v1_number, v2_number;
            scanf("%d %d", &v1_number, &v2_number);
            v1_number--;
            v2_number--;

            printf("Scalar of vectors = ");;
            outputStream(Scalar(data[v1_number], data[v2_number]));
            printf("\n");

            break;
        }
    }

    return;
}

void OutPutMenu(struct Vector3** data, int counter)
{
    printf("\t-Output Menu-\n");
    printf("Enter the number of vector (1-%d)\n", counter);
    int number;
    scanf("%d", &number);
    number--;
    OutPutVector(data[number]);
    return;
}

void OutPutVector(struct Vector3* vector)
{
    printf("vector output\n");
    printf("\t-");
    outputStream(GetX(vector));
    printf("\n\t-");
    outputStream(GetY(vector));
    printf("\n\t-");
    outputStream(GetZ(vector));
    printf("\n");

    return;
}