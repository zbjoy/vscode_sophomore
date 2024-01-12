#include "seqStack.h"

void printError(char* str, char* errorMsg, char* pos)
{
    printf("Error string: %s : %s\n", str, errorMsg);
    int num = pos - str;
    printf("              ");
    while(num--)
    {
        printf(" ");
    }
    printf("A");
}

void test()
{
    char* str;
    str = "a+b/(a-b)-(c+e()";
    char* p = str;
    SeqStack stack = init_SeqStack();
    while(*p != '\0')
    {
        if(*p == '(')
        {
            push_SeqStack(stack, p);
        }
        else if(*p == ')')
        {
            if(isEmpty_SeqStack(stack))
            {
                printError(str, "no left match", p);
            }
            else
            {
                pop_SeqStack(stack);
            }
        }
        p++;
    }
    while(!isEmpty_SeqStack(stack))
    {
        printError(str, "no right match", top_SeqStack(stack));
        pop_SeqStack(stack);
    }
}

int main()
{
    test();
    return 0;
}