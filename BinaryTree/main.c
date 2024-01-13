#include <stdio.h>

#include "BinaryTree.h"

void test01()
{
    struct BinaryNode nodeA = {'A', NULL, NULL};
    struct BinaryNode nodeB = {'B', NULL, NULL};
    struct BinaryNode nodeC = {'C', NULL, NULL};
    struct BinaryNode nodeD = {'D', NULL, NULL};
    struct BinaryNode nodeE = {'E', NULL, NULL};
    struct BinaryNode nodeF = {'F', NULL, NULL};
    struct BinaryNode nodeG = {'G', NULL, NULL};

    nodeA.lChild = &nodeB;
    nodeA.rChild = &nodeF;
    nodeB.lChild = &nodeC;
    nodeB.rChild = &nodeD;
    nodeD.lChild = &nodeE;
    nodeF.rChild = &nodeG;

    recursion(&nodeA);

    int num = 0;
    calculateLeafNum(&nodeA, &num);
    printf("%d   ", num);

    int height = getTreeHeight(&nodeA);
    printf("%d", height);

    struct BinaryNode* tree = copyTree(&nodeA);
    printf("\n");
    recursion(tree);

    freeTree(tree);
    tree = NULL;
    recursion(tree);
}

int main()
{
    test01();
    return 0;
}