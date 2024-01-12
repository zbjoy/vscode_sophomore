#include <stdio.h>
#include "LinkQueue.h"

struct Person
{
    LinkQueue node;
    char name[64];
    int age;
};

void printTest_Queue(LinkQueue queue)
{
    printf("Front: %s,%d\n", ((struct Person*)front_LinkQueue(queue))->name, ((struct Person*)front_LinkQueue(queue))->age);
    printf("Back: %s,%d\n", ((struct Person*)back_LinkQueue(queue))->name, ((struct Person*)back_LinkQueue(queue))->age);
}

void test01()
{
    struct Person p1 = {NULL, "aaa", 11};
    struct Person p2 = {NULL, "bbb", 22};
    struct Person p3 = {NULL, "ccc", 33};
    struct Person p4 = {NULL, "ddd", 44};
    struct Person p5 = {NULL, "eee", 55};
    LinkQueue queue = init_LinkQueue();
    push_LinkQueue(queue, &p1);
    printTest_Queue(queue);
    push_LinkQueue(queue, &p2);
    printTest_Queue(queue);
    push_LinkQueue(queue, &p3);
    printTest_Queue(queue);
    push_LinkQueue(queue, &p4);
    printTest_Queue(queue);
    push_LinkQueue(queue, &p5);
    printTest_Queue(queue);
    pop_LinkQueue(queue);
    printTest_Queue(queue);
}

int main()
{
    test01();
    return 0;
}