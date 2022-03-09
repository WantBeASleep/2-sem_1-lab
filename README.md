#### а что происходит?

***

***структура***
- *main.c*
  - *Vector3.c*
    - *intVector3.c*
    - *doubleVector3.c*
- *Vector3.h*
- *intVector3.h*
- *doubleVector3.h*

##### main.c

***

Суть `main.c`: 
- хранение наших веторов:  
```c
struct Vector3** data = (struct Vector3**)malloc(counter * sizeof(struct Vector3*));
```
- оформление меню в терминале(*пример объявления функций*)
```c
void menuOperator(struct Vector3**, int);
int mainMenu();
void vectorActionsMenu(struct Vector3**, int);
...
```
- определения типа данных с которыми работаем
  - В данном случае речь идет про `int` и `double`
- вызов функций из `Vector3.c` в зависимости от задачи
- для типизированного вывода
  - В си мы всегда в `scanf()` ставим типизированные флаги, будь то `%d`, `lf` для `int` и `double` соответственно, для этого можно написать функцию для вывода конкретного типа в файле тип, например `intVector3.c` и создать указатель на эту функцию в `main.c` вот пример:
```c
//main.c
//объявление:
void (*outputStream)(void*);
//в зависимости от типа приравнивание
case int:
        {
            
            outputStream = IntOutputStream;
            ...
```
```c
//intVector3.c
// IntOutputStream
void IntOutputStream(void* number)
{
    printf("%d", *(int*)number);
}
```

#### Vector3.c

***

`Vector3.c` нам нужен для создания *абстрактного типа данных* , который может хранить любой тип данных, и для *универсальных* функций, которыми мы и оперируем в `main.c`, ясно что они не должны зависить от типа данных, на то они и *универсальные*  
- структура данных (*атд*)
```c
struct Vector3
{
    struct RingInfo* ringinfo;
    void *x;
    void *y;
    void *z;
};

struct RingInfo
{
    size_t size;
    void* zero;
    void* one;
    void* (*sum)(void*, void*);
    void* (*minus)(void*, void*);
    void* (*scalar)(void**, void**);
};
```
  - `struct Vector3`
    - Нужен для *универсального* хранения *компонентов* векторов
  - `struct RingInfo`
    - Структура для хранения ссылок на *функции*, которые зависят от типа данных
      - Функции в *ringinfo* не универсальны, их суть в конкретной обработке данных, то есть для `int` и `float` разные, мы их пропишем и вставим в `ringinfo`
- Универсальные функции
  - Создание `ringinfo`
  - *Универсальные* функции обработки
    - Создание вектора, например: `struct Vector3* E_2(struct RingInfo*);`
    - Вывод компонента вектора, например: `void* GetY(struct Vector3*);`
    - Обработка значений вектора, например: `struct Vector3* Sum(struct Vector3*, struct Vector3*);`
      - Уже в *универсальных* функциях мы будем вызывать типизированные, но важно помнить: так как функции обработки **универсальны**, то их суть обрабатывать `void`'ы вернувшиеся от *типизированных* функций и запихивать их в вектор, например функция суммы:
```c
struct Vector3* Sum(struct Vector3* v1, struct Vector3* v2)
{
    struct Vector3* result = (struct Vector3 *)malloc(sizeof(struct Vector3));
    result->ringinfo = v1->ringinfo;
    result->x = result->ringinfo->sum(v1->x, v2->x);
    result->y = result->ringinfo->sum(v1->y, v2->y);
    result->z = result->ringinfo->sum(v1->z, v2->z);

    return result;
}
```

#### int/double, типизированный функционал

***

Пишем *типизированные* функции, помня что их результат будет уже распределен в `Vector3.c`, например `intSum`:  
```c

void *sumInt(void *a1, void *a2)
{
    int *ia1 = (int *)a1;
    int *ia2 = (int *)a2;
    
    int *res = (int *)malloc(sizeof(int));
    *res = *ia1 + *ia2;

    return (void*)res;
}
```