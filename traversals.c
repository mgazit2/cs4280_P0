/* traversals.c */
#include "node.h"
#include <stdlib.h>
#include <stdio.h>

void inorder(struct Node *root) {
	if (root != NULL) {
		inorder(root -> left);
		printf("%s\n", root -> data);
		inorder(root -> right);
	}
}

void preorder(struct Node *root) {
        if (root != NULL) {
		printf("%s\n", root -> data);
                inorder(root -> left);
                inorder(root -> right);
        }
}

void postorder(struct Node *root) {
        if (root != NULL) {
                inorder(root -> left);
                inorder(root -> right);
		printf("%s\n", root -> data);
        }
}
