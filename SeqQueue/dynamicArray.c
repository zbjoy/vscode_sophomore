#include "dynamicArray.h"

dynamicArray* initArray()
{
    dynamicArray* p = malloc(sizeof(dynamicArray));
    p->pArr = malloc(sizeof(void*) * 5);
    p->m_Capacity = 5;
    p->m_Size = 0;
    return p;
}

void insertArray(dynamicArray* arr, void* data, int pos)
{
    if(data == NULL)
    {
        return;
    }

    if(pos < 0 || pos > arr->m_Size)
    {
        pos = arr->m_Size;
    }

    if(arr->m_Capacity == arr->m_Size)
    {
        void** newSpace = malloc(sizeof(void*) * arr->m_Capacity * 2);
        memcpy(newSpace, arr->pArr, sizeof(void*) * arr->m_Size);
        free(arr->pArr);
        arr->m_Capacity = arr->m_Capacity * 2;
        arr->pArr = newSpace;
    }

    for(int i = arr->m_Size - 1; i >= pos; i--)
    {
        // memcpy(arr->pArr[i+1], arr->pArr[i], sizeof(void*));
        arr->pArr[i+1] = arr->pArr[i];
    }
    //memcpy(arr->pArr[pos], data, sizeof(void*));
    arr->pArr[pos] = data;
    arr->m_Size++;
}

void dynamicArray_Print(dynamicArray* arr, void (*print)(void*))
{
    for(int i = 0; i < arr->m_Size; i++)
    {
        print(arr->pArr[i]);
    }
}

void removeArray(dynamicArray *arr, int pos)
{
    if(arr == NULL)
    {
        return;
    }

    if(arr->m_Size == 0)
    {
        return;
    }

    if(arr->m_Size <= pos)
    {
        pos = arr->m_Size - 1;
    }

    for(int i = pos; i < arr->m_Size - 1; i++)
    {
        arr->pArr[i] = arr->pArr[i+1];
    }
    arr->m_Size--;
}

void myPrint(void* data)
{
    int* num = data;
    printf("%d ", *num);
}

// int main()
// {
//     dynamicArray* arr = initArray();
//     int a = 2;
//     int b = 6;
//     insertArray(arr, &a, 0);
//     dynamicArray_Print(arr, myPrint);
//     printf("\n");
//     insertArray(arr, &b, 1);
//     dynamicArray_Print(arr, myPrint);
//     return 0;
// }