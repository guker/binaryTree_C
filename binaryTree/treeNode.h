#ifndef TREENODE_H
#define TREENODE_H

typedef struct treeNode* treePTR;
typedef struct treeNode{
	int data;
	treePTR left, right;
}treeNode;

#endif