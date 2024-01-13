#include <stdio.h>

#include "BinaryTree.h"

void test01()
{
    struct BinaryNode nodeA = {'A', NULL, NULL, 0};
    struct BinaryNode nodeB = {'B', NULL, NULL, 0};
    struct BinaryNode nodeC = {'C', NULL, NULL, 0};
    struct BinaryNode nodeD = {'D', NULL, NULL, 0};
    struct BinaryNode nodeE = {'E', NULL, NULL, 0};
    struct BinaryNode nodeF = {'F', NULL, NULL, 0};
    struct BinaryNode nodeG = {'G', NULL, NULL, 0};

    nodeA.lChild = &nodeB;
    nodeA.rChild = &nodeF;
    nodeB.lChild = &nodeC;
    nodeB.rChild = &nodeD;
    nodeD.lChild = &nodeE;
    nodeF.rChild = &nodeG;

    recursion(&nodeA);
    printf("\n");
    myRecursion(&nodeA);

    int num = 0;
    calculateLeafNum(&nodeA, &num);
    printf("%d   ", num);

    int height = getTreeHeight(&nodeA);
    printf("%d", height);

    struct BinaryNode* tree = copyTree(&nodeA);
    printf("\n");
    recursion(tree);
    printf("\n");
    myRecursion(tree);

    freeTree(tree);
    tree = NULL;
    recursion(tree);
    //myRecursion(tree);
}



int main()
{
    test01();
    return 0;
}