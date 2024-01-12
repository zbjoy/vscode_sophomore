#include <stdio.h>
#include "LinkStack.h"

struct Person
{
    LinkStack node;
    char name[64];
    int age;
};

void print_Person(struct Person* per)
{
    printf("%s, %d\n", per->name, per->age);
}

void test01()
{
    LinkStack stack = init_LinkStack();
    struct Person p1 = {NULL, "aaa", 11};
    struct Person p2 = {NULL, "bbb", 22};
    struct Person p3 = {NULL, "ccc", 33};
    struct Person p4 = {NULL, "ddd", 44};
    struct Person p5 = {NULL, "eee", 55};
    push_LinkStack(stack, &p1);
    print_Person(top_LinkStack(stack));
    push_LinkStack(stack, &p2);
    print_Person(top_LinkStack(stack));
    push_LinkStack(stack, &p3);
    print_Person(top_LinkStack(stack));
    push_LinkStack(stack, &p4);
    print_Person(top_LinkStack(stack));
    push_LinkStack(stack, &p5);
    print_Person(top_LinkStack(stack));
}

int main()
{
    //test01();
    return 0;
}