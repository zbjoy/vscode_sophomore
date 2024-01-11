#include <stdio.h>
#include "seqStack.h"

struct Person
{
    char name[64];
    int age;
};

void print_Person(struct Person* per)
{
    printf("Name:%s  Age:%d\n", per->name, per->age);
}

int main()
{
    SeqStack stack = init_SeqStack();
    struct Person p1 = {"aaa", 11};
    struct Person p2 = {"bbb", 22};
    struct Person p3 = {"ccc", 33};
    struct Person p4 = {"ddd", 44};
    struct Person p5 = {"eee", 55};

    push_SeqStack(stack, &p1);
    print_Person(top_SeqStack(stack));
    push_SeqStack(stack, &p2);
    print_Person(top_SeqStack(stack));
    push_SeqStack(stack, &p3);
    print_Person(top_SeqStack(stack));
    push_SeqStack(stack, &p4);
    print_Person(top_SeqStack(stack));
    push_SeqStack(stack, &p5);
    print_Person(top_SeqStack(stack));
    pop_SeqStack(stack);
    print_Person(top_SeqStack(stack));
    destory_SeqStack(stack);
    return 0;
}