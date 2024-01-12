#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dynamicArray
{
    void** pArr;
    int m_Capacity;
    int m_Size;
}dynamicArray;

dynamicArray *initArray();

void insertArray(dynamicArray *arr, void *data, int pos);

void dynamicArray_Print(dynamicArray *arr, void (*print)(void *));

void removeArray(dynamicArray* arr, int pos);
