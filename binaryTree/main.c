#include "treeFunction.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

	/*
						        10
						20		           30
					44	   60		   95      100
				 70   83					 22   111
												    27
	*/
	treePTR node12 = makeNode(27, NULL, NULL);
	treePTR node11 = makeNode(111, NULL, node12);
	treePTR node10 = makeNode(22, NULL, NULL);
	treePTR node9 = makeNode(83, NULL, NULL);
	treePTR node8 = makeNode(70, NULL, NULL);
	treePTR node7 = makeNode(100, node10, node11);
	treePTR node6 = makeNode(95, NULL, NULL);
	treePTR node5 = makeNode(60, NULL, NULL);
	treePTR node4 = makeNode(44, node8, node9);
	treePTR node3 = makeNode(30, node6, node7);
	treePTR node2 = makeNode(20, node4, node5);
	treePTR node1 = makeNode(10, node2, node3);
	treePTR forcopy = makeNode(0, NULL, NULL);

	forcopy = copyTree(node1);
	printf("----------preorder----------\n");
	preOrder_iter(node1);
	printf("\n");
	preOrder(forcopy);
	printf("\n\n");

	printf("----------inorder----------\n");
	inOrder_iter(node1);
	printf("\n");
	inOrder(forcopy);
	printf("\n\n");

	printf("----------postorder----------\n");
	postOrder_iter(node1);
	printf("\n");
	postOrder(forcopy);
	printf("\n\n");

	printf("----------levelorder----------\n");
	levelOrder(node1);
	printf("\n\n");

	if (equalTree(forcopy, node1)){
		printf("The tree forcopy and node1 are same.\n");
	}
	printf("The Max node value of this tree is ... %d\n", getMax(node1));
	printf("The Sum of this tree's node value is ... %d\n", sumTree(node1));
	printf("\n");
	deallocate_Tree(node1);
	return 0;
}