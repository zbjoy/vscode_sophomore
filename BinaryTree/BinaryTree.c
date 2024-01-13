#include "BinaryTree.h"

void recursion(struct BinaryNode *node)
{
    if(node == NULL)
    {
        return;
    }

    printf("%c  ", node->data);
    recursion(node->lChild);
    recursion(node->rChild);
}

void calculateLeafNum(struct BinaryNode * node, int* num)
{
    if(node == NULL)
    {
        return;
    }

    calculateLeafNum(node->lChild, num);
    calculateLeafNum(node->rChild, num);

    if(node->lChild == NULL && node->rChild == NULL)
    {
        (*num)++;
    }
}

int getTreeHeight(struct BinaryNode *node)
{
    if(node == NULL)
    {
        return 0;
    }

    int leftHeight = getTreeHeight(node->lChild);
    int rightHeight = getTreeHeight(node->rChild);

    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;

}

struct BinaryNode *copyTree(struct BinaryNode *node)
{
    if(node == NULL)
    {
        return NULL;
    }
    struct BinaryNode* newTree = malloc(sizeof(struct BinaryNode));

    newTree->lChild = copyTree(node->lChild);
    newTree->rChild = copyTree(node->rChild);

    newTree->data = node->data;
    return newTree;
}

void freeTree(struct BinaryNode* node)
{
    if(node == NULL)
    {
        return;
    }

    freeTree(node->lChild);
    freeTree(node->rChild);

    free(node);
    node = NULL;
}
