#ifndef __TREEFUNCTION_H__
#define __TREEFUNCTION_H__

#include "treeNode.h"

treePTR makeNode(int data, treePTR leftNode, treePTR rightNode);
int getValue(treePTR node);
void inOrder(treePTR root);
void inOrder_iter(treePTR root);
void preOrder(treePTR root);
void preOrder_iter(treePTR root);
void postOrder(treePTR root);
void postOrder_iter(treePTR root);
void levelOrder(treePTR root);
treePTR copy(treePTR input);
int equalTree(treePTR x, treePTR y);
int sumTree(treePTR root);
int getMax(treePTR root);

#endif