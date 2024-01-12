#include "LinkStack.h"

struct LinkNode
{
    struct LinkNode* next;
};

struct LStack
{
    struct LinkNode header;
    int m_Size;
};

LinkStack init_LinkStack()
{
    struct LStack* stack = malloc(sizeof(struct LStack));

    stack->header.next = NULL;
    stack->m_Size = 0;

    return stack;
}

void push_LinkStack(LinkStack tStack, void *data)
{
    if(tStack == NULL || data == NULL)
    {
        return;
    }

    struct LStack* stack = tStack;

    struct LinkNode* node = data;
    node->next = stack->header.next;
    stack->header.next = node;
    stack->m_Size++;
}

void pop_LinkStack(LinkStack tStack)
{
    if(tStack == NULL)
    {
        return;
    }

    struct LStack* stack = tStack;

    stack->header.next = stack->header.next->next;
    stack->m_Size--;
}

void *top_LinkStack(LinkStack tStack)
{
    if(isEmpty_LinkStack(tStack))
    {
        return NULL;
    }
    struct LStack* stack = tStack;
    return stack->header.next;
}

int isEmpty_LinkStack(LinkStack tStack)
{
    if(tStack == NULL)
    {
        return -1;
    }

    struct LStack* stack = tStack;

    if(stack->m_Size == 0)
    {
        return 1;
    }
    return 0;
}

int size_LinkStack(LinkStack tStack)
{
    if(tStack == NULL)
    {
        return -1;
    }

    struct LStack* stack = tStack;
    return stack->m_Size;
}

void destroy_LinkStack(LinkStack tStack)
{
    if(tStack == NULL)
    {
        return;
    }

    struct LStack* stack = tStack;
    free(stack);
    stack = NULL;
}
