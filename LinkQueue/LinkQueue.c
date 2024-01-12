#include "LinkQueue.h"

struct LinkNode
{
    struct LinkNode* next;
};

struct LQueue 
{
    struct LinkNode header;
    void* tail;
    int m_Size;
};

LinkQueue init_LinkQueue()
{
    struct LQueue* queue = malloc(sizeof(struct LQueue));

    queue->header.next = NULL;
    queue->tail = &queue->header;
    queue->m_Size = 0;

    return queue;
}

void push_LinkQueue(LinkQueue tQueue, void *data)
{
    if(tQueue == NULL)
    {
        return;
    }

    struct LQueue* queue = tQueue;
    if(data == NULL)
    {
        return;
    }

    struct LinkNode* node = data;
    node->next = ((struct LinkNode*)(queue->tail))->next;
    ((struct LinkNode*)(queue->tail))->next = node;
    
    queue->tail = ((struct LinkNode*)(queue->tail))->next;

    queue->m_Size++;
}

void pop_LinkQueue(LinkQueue tQueue)
{
    if(tQueue == NULL)
    {
        return;
    }

    struct LQueue* queue = tQueue;
    if(queue->m_Size == 0)
    {
        return;
    }

    queue->header.next = queue->header.next->next;
    queue->m_Size--;

    if(queue->m_Size == 0)
    {
        queue->tail = &queue->header;
    }
}

void *front_LinkQueue(LinkQueue tQueue)
{
    if(tQueue == NULL)
    {
        return NULL;
    }

    struct LQueue* queue = tQueue;

    if(queue->m_Size == 0)
    {
        return NULL;
    }

    return queue->header.next;
}

void *back_LinkQueue(LinkQueue tQueue)
{
    if(tQueue == NULL)
    {
        return NULL;
    }

    struct LQueue* queue = tQueue;

    if(queue->m_Size == 0)
    {
        return NULL;
    }

    return queue->tail;
}

int size_LinkQueue(LinkQueue tQueue)
{
    if(tQueue == NULL)
    {
        return -1;
    }

    struct LQueue* queue = tQueue; 
    return queue->m_Size;
}

void destroy_LinkQueue(LinkQueue tQueue)
{
    if(tQueue == NULL)
    {
        return;
    }

    struct LQueue* queue = tQueue; 
    free(queue);
    queue = NULL;
}
