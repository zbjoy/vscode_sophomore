#include "seqStack.h"

struct SStack
{
    void* data[MAX];
    int m_Size;
};

SeqStack init_SeqStack()
{
    struct SStack* stack = malloc(sizeof(struct SStack));
    if(stack == NULL)
    {
        return NULL;
    }
    
    memset(stack->data, 0, sizeof(void*) * MAX);
    stack->m_Size = 0;

    return stack;
}

void push_SeqStack(SeqStack tStack, void *data)
{
    if(tStack == NULL)
    {
        return;
    }
    struct SStack* stack = tStack;
    if(stack->m_Size == MAX)
    {
        return;
    }

    stack->data[stack->m_Size++] = data;
}

void *top_SeqStack(SeqStack tStack)
{
    if(tStack == NULL)
    {
        return NULL;
    }
    struct SStack* stack = tStack;
    if(stack->m_Size == 0)
    {
        return NULL;
    }

    return stack->data[stack->m_Size-1];
}

void pop_SeqStack(SeqStack tStack)
{
    if(tStack == NULL)
    {
        return;
    }
    struct SStack* stack = tStack;
    if(stack->m_Size == 0)
    {
        return;
    }
    stack->data[--stack->m_Size] = NULL;
}

int isEmpty_SeqStack(SeqStack tStack)
{
    if(tStack == NULL)
    {
        return -1;
    }
    struct SStack* stack = tStack;
    if(stack->m_Size == 0)
    {
        return 1;
    }
    return 0;
}

int size_SeqStack(SeqStack tStack)
{
    if(tStack == NULL)
    {
        return -1;
    }
    struct SStack* stack = tStack;
    return stack->m_Size;
}

void destory_SeqStack(SeqStack tStack)
{
    if(tStack == NULL)
    {
        return;
    }
    struct SStack* stack = tStack;
    free(stack);
    stack = NULL;
}
