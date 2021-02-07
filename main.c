/* main.c */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "node.h"
#include "traversals.h"
#include "tree.h"

int main(int argc, char *argv[]) {
	if (argc == 1) {
		printf("Number of arguments is %d\n", argc-1);
		printf("Please call this process w/ at least 1 string file\n");
		return EXIT_SUCCESS;
	}
	char x[30] = "hello";
	printf("I'm working\n");
	struct Node *root;
	root = new_node("hh");
	printf("%s\n", root -> data);
	preorder(root);
	insert_node(root, x);
	postorder(root);
	//printf("%d\n", a + b);
	free(root);
	return 0;
}
