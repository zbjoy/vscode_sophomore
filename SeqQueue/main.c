#include <stdio.h>
#include "SeqQueue.h"

struct Person
{
    char name[64];
    int age;
};

void printTest_Queue(SeqQueue queue)
{
    printf("Front: %s,%d\n", ((struct Person*)front_SeqQueue(queue))->name, ((struct Person*)front_SeqQueue(queue))->age);
    printf("Back: %s,%d\n", ((struct Person*)back_SeqQueue(queue))->name, ((struct Person*)back_SeqQueue(queue))->age);
}

void test()
{
    struct Person p1 = {"aaa", 11};
    struct Person p2 = {"bbb", 22};
    struct Person p3 = {"ccc", 33};
    struct Person p4 = {"ddd", 44};
    struct Person p5 = {"eee", 55};
    SeqQueue queue = init_SeqQueue();
    push_SeqQueue(queue, &p1);
    printTest_Queue(queue);
    push_SeqQueue(queue, &p2);
    printTest_Queue(queue);
    push_SeqQueue(queue, &p3);
    printTest_Queue(queue);
    push_SeqQueue(queue, &p4);
    printTest_Queue(queue);
    push_SeqQueue(queue, &p5);
    printTest_Queue(queue);
    pop_SeqQueue(queue);
    printTest_Queue(queue);
}

int main()
{
    test();
    return 0;
}