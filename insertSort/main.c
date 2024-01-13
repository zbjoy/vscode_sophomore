#include <stdio.h>

#include "seqStack.h"

void insertSort(int* arr, int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        if(arr[i] > arr[i+1])
        {
            int temp = arr[i+1];
            int j = i;
            for(; j >= 0 && arr[j] > temp; j--)
            {
                arr[j+1] = arr[j];
            }
            arr[j+1] = temp;   
        }
    }
}

void test()
{
    int arr[] = {1, 5, 3, 4, 2};
    insertSort(arr, sizeof(arr) / sizeof(arr[0]));
    for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    test();
    return 0;
}