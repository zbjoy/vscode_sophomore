#include <stdio.h>
#include <stdlib.h>

typedef void* LinkStack;

LinkStack init_LinkStack();

void push_LinkStack(LinkStack tStack, void* data);

void pop_LinkStack(LinkStack tStack);

void* top_LinkStack(LinkStack tStack);

int isEmpty_LinkStack(LinkStack tStack);

int size_LinkStack(LinkStack tStack);

void destroy_LinkStack(LinkStack tStack);