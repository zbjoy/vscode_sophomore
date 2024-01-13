#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

typedef void* SeqStack;

SeqStack init_SeqStack();

void push_SeqStack(SeqStack tStack, void* data);

void* top_SeqStack(SeqStack tStack);

void pop_SeqStack(SeqStack tStack);

int isEmpty_SeqStack(SeqStack tStack);

int size_SeqStack(SeqStack tStack);

void destory_SeqStack(SeqStack tStack);