#include "SeqQueue.h"


SeqQueue init_SeqQueue()
{
    dynamicArray* queue = initArray();
    return queue;
}

void push_SeqQueue(SeqQueue tQueue, void *data)
{
    if(tQueue == NULL)
    {
        return;
    }

    if(data == NULL)
    {
        return;
    }

    insertArray(tQueue, data, -1);
}

void pop_SeqQueue(SeqQueue tQueue)
{
    if(tQueue == NULL)
    {
        return;
    }

    struct dynamicArray* queue = tQueue;
    if(queue->m_Size == 0)
    {
        return;
    }

    removeArray(queue, 0);
}

int isEmpty_SeqQueue(SeqQueue tQueue)
{
    if(tQueue == NULL)
    {
        return -1;
    }

    struct dynamicArray* queue = tQueue;
    if(queue->m_Size == 0)
    {
        return 1;
    }
    return 0;
}

int size_SeqQueue(SeqQueue tQueue)
{
    if(tQueue == NULL)
    {
        return -1;
    }

    struct dynamicArray* queue = tQueue;

    return queue->m_Size;
}

void* front_SeqQueue(SeqQueue tQueue)
{
    if(tQueue == NULL)
    {
        return NULL;
    }

    if(isEmpty_SeqQueue(tQueue))
    {
        return NULL;
    }

    struct dynamicArray* queue = tQueue;
    return queue->pArr[0];
}

void* back_SeqQueue(SeqQueue tQueue)
{
    if(tQueue == NULL)
    {
        return NULL;
    }

    if(isEmpty_SeqQueue(tQueue))
    {
        return NULL;
    }

    struct dynamicArray* queue = tQueue;
    return queue->pArr[queue->m_Size-1];
}

void destroy_SeqQueue(SeqQueue tQueue)
{
    if(tQueue == NULL)
    {
        return;
    }

    struct dynamicArray* queue = tQueue;
    free(queue);
}