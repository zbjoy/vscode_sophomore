#include <stdio.h>
#include <stdlib.h>
#include "seqStack.h"

struct BinaryNode
{
    char data;
    struct BinaryNode* rChild;
    struct BinaryNode* lChild;
    int flag;
};

void recursion(struct BinaryNode* node);

void calculateLeafNum(struct BinaryNode* node, int* num);

int getTreeHeight(struct BinaryNode* node);

struct BinaryNode* copyTree(struct BinaryNode* node);

void freeTree(struct BinaryNode* node);

void myRecursion(struct BinaryNode* node);