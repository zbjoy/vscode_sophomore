#include <stdio.h>
#include <stdlib.h>

struct BinaryNode
{
    char data;
    struct BinaryNode* rChild;
    struct BinaryNode* lChild;
};

void recursion(struct BinaryNode* node);

void calculateLeafNum(struct BinaryNode* node, int* num);

int getTreeHeight(struct BinaryNode* node);

struct BinaryNode* copyTree(struct BinaryNode* node);

void freeTree(struct BinaryNode* node);