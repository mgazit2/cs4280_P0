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
	
	//Initial value check
	if (root == NULL)
		return new_node(x);
	//Var declerations
	int sum_of_x;
	int sum_of_root;
	
	//If the string is long
	if (strlen(x) >= 2)
		sum_of_x = x[0] + x[1];
	//If the string is a single char
	else if (strlen(x) < 2)
		sum_of_x = x[0];

	//Same as above, but for the root data
	if (strlen(root -> data) >= 2)
		sum_of_root = root -> data[0] + root -> data[1];
	else if (strlen(root -> data) < 2)
		sum_of_root = root -> data[0];
	
	//Decide direction
	if (sum_of_x > sum_of_root)
		root -> right = insert_node(root -> right, x);
	else if (sum_of_x < sum_of_root)
		root -> left = insert_node(root -> left, x);
	else if (sum_of_x == sum_of_root) {
		strcat(root -> data, x);
	}
	return root; 
}
