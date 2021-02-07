/* tree.c */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "node.h"
struct Node* new_node(char* x) {
        struct Node *root;
        root = malloc(sizeof(struct Node));
        root -> data = x;
        root -> left = NULL;
        root -> right = NULL;
        return root;
}

struct Node* insert_node(struct Node* root, char* x) {
	if (root == NULL)
		return new_node(x);
	printf("Another fuck you\n");
	int sum_of_x;
	int sum_of_root;
	if (strlen(x) >= 2)
		sum_of_x = x[0] + x[1];
	else if (strlen(x) < 2)
		sum_of_x = x[0];
	if (strlen(root -> data) >= 2)
		sum_of_root = root -> data[0] + root -> data[1];
	if (strlen(root -> data) < 2)
		sum_of_root = root -> data[0];
	else if (sum_of_x > sum_of_root)
		root -> right = insert_node(root -> right, x);
	else
		root -> left = insert_node(root -> left, x);
	return root; 
}
