#include <stdio.h>
#include <stdlib.h>

typedef void* LinkList;

struct ListNode
{
    struct ListNode* next;
};

struct LList
{
    struct ListNode header;
    int m_Size;
};

LinkList init_List()
{
    struct LList* pList = malloc(sizeof(struct LList));
    if(pList == NULL)
    {
        return NULL;
    }

    pList->header.next = NULL;
    pList->m_Size = 0;

    return pList;
}

void insert_List(void* list, int pos, void* data)
{
    struct LList* pList = list;
    
    if(pList == NULL)
    {
        return;
    }

    if(data == NULL)
    {
        return;
    }

    if(pos < 0 || pos > pList->m_Size - 1)
    {
        pos = pList->m_Size;
    }
    
    struct ListNode* t = data;
    struct ListNode* pCurrent = &pList->header;

    for(int i = 0; i < pos; i++)
    {
        pCurrent = pCurrent->next;
    }

    t->next = pCurrent->next;
    //pCurrent->next = t;
    ((struct ListNode*)(&(pCurrent->next)))->next = t;

    pList->m_Size++;
    
}

void removeByPos(LinkList list, int pos)
{
    struct LList* pList = list;
    if(pos < 0 || pos >= pList->m_Size)
    {
        return;
    }
    struct ListNode* pCurrent = &pList->header;
    for(int i = 0; i < pos; i++)
    {
        pCurrent = pCurrent->next;
    }
    struct ListNode* pDel = pCurrent->next;
    pCurrent->next = pDel->next;

    pList->m_Size--;
}

void foreach_List(LinkList list, void (*myPrint)(void*))
{
    struct LList* pList = list;

    struct ListNode* pCurrent = &pList->header;

    for(int i = 0; i < pList->m_Size; i++)
    {
        pCurrent = pCurrent->next;
        myPrint(pCurrent);
    }
}

///////////////////////////////////////////////////////////////////////////////////////

struct Person
{
    LinkList link;
    char name[64];
    int age;
};

void print_Person(void* data)
{
    struct Person* per = data;
    printf("Name:%s Age:%d\n", per->name, per->age);
}

int main()
{
    LinkList list = init_List();
    struct Person p1 = {NULL, "aaa", 11};
    struct Person p2 = {NULL, "bbb", 22};
    struct Person p3 = {NULL, "ccc", 33};
    struct Person p4 = {NULL, "ddd", 44};
    struct Person p5 = {NULL, "eee", 55};

    insert_List(list, -1, &p1);
    insert_List(list, -1, &p2);
    insert_List(list, -1, &p3);
    insert_List(list, -1, &p4);
    insert_List(list, -1, &p5);

    foreach_List(list, print_Person);

    removeByPos(list, 2);

    foreach_List(list, print_Person);
    
    return 0;
}