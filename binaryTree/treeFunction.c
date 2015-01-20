#include "treeNode.h"
#include "myStack.h"
#include "myQueue.h"
#include <stdio.h>
#include <stdlib.h>

treePTR makeNode(int data, treePTR leftNode, treePTR rightNode){
	treePTR root = (treePTR)malloc(sizeof(treeNode));
	root->data = data;
	root->left = leftNode;
	root->right = rightNode;
	return root;
}

int getValue(treePTR node){
	int value = node->data;
	return value;
}

void inOrder(treePTR root){//Recursive inorder
	if (root){
		if (root->left) inOrder(root->left);
		printf("%d ", root->data);
		if (root->right) inOrder(root->right);
	}
}

void inOrder_iter(treePTR root){
	stackType s;
	init_stack(&s);
	while (1){
		while (root){
			push(&s, root);
			root = root->left;
		}
		root = pop(&s);
		printf("%d ", root->data);
		if (is_sEmpty(&s) && !(root->right)) break;
		root = root->right;
	}
}

void preOrder(treePTR root){ //Recursive preorder 
	if (root){
		printf("%d ", root->data);
		if (root->left) preOrder(root->left);
		if (root->right) preOrder(root->right);
	}
}

void preOrder_iter(treePTR root){
	stackType s;
	init_stack(&s);
	if (!root) return;
	else push(&s, root);
	while (1){
		root = pop(&s);
		printf("%d ", root->data);
		if (root->right) push(&s, root->right);
		if (root->left) push(&s, root->left);
		if (is_sEmpty(&s)) break;
	}
}

void postOrder(treePTR root){ //Recursive postorder
	if (root){
		if (root->left) postOrder(root->left);
		if (root->right) postOrder(root->right);
		printf("%d ", root->data);
	}
}

void postOrder_iter(treePTR root){
	stackType s, bs;
	init_stack(&s);
	init_stack(&bs);
	if (!root) return;
	else push(&s, root);
	while(!is_sEmpty(&s)){
		root = pop(&s);
		push(&bs, root);
		if (root->left) push(&s, root->left);
		if (root->right) push(&s, root->right);
	}
	while (!is_sEmpty(&bs)){
		printf("%d ", pop(&bs)->data);
	}
}

void levelOrder(treePTR root){
	QType q;
	init_Q(&q);
	if(!root) return;
	else enqueue(&q, root);
	while(1){
		root = dequeue(&q);
		printf("%d ", root->data);
		if(root->left) enqueue(&q, root->left);
		if(root->right) enqueue(&q, root->right);
		if(is_qEmpty(&q)) break;
	}
}

treePTR copy(treePTR input){
	if (input){
		treePTR output = (treePTR)malloc(sizeof(treeNode));
		output->data = input->data;
		output->left = copy(input->left);
		output->right = copy(input->right);
		return output;
	}
	return NULL;
}

int equalTree(treePTR x, treePTR y){ //TRUE : return 1, FALSE : return 0
	if (!x && !y) return 1;
	if (x && y){
		if ((x->data == y->data) &&
			equalTree(x->left, y->left) &&
			equalTree(x->right, y->right)) return 1;
		else return 0;
	}
	else return 0;
}

int sumTree(treePTR root){
	int leftsum, rightsum;
	if (!root) return 0;
	else{
		leftsum = sumTree(root->left);
		rightsum = sumTree(root->right);
		return (root->data + leftsum + rightsum);
	}
}

int getMax(treePTR root){
	if (root){
		int max = root->data;
		int k = getMax(root->left);
		if (max < k)
			max = k;
		k = getMax(root->right);
		if (max < k)
			max = k;
		return max;
	}
	else return 0;
}