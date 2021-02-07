/* main.c */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "node.h"
#include "traversals.h"

struct Node *new_node(char *d) {
	struct Node *root;
	root = malloc(sizeof(struct Node));
	root -> data = d;
	root -> left = NULL;
	root -> right = NULL;

	return root;
}

int main(int argc, char *argv[]) {
	printf("I'm working\n");
	struct Node *root;
	root = new_node("hh");
	printf("%s\n", root -> data);
	preorder(root);
	return 0;
}
