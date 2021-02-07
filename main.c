/* main.c */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "node.h"
#include "traversals.h"
#include "tree.h"

/* Prototypes */
static void print_inorder(struct Node* root);
static void print_preorder(struct Node* root);
static void print_postorder(struct Node* root);
/* End Prototypes */

int main(int argc, char *argv[]) {
	//Input validation
	if (argc == 1) {
		printf("Number of arguments is %d\n", argc-1);
		printf("Please call this process w/ at least 1 string file\n");
		return EXIT_SUCCESS;
	}
	//char x[30];
	printf("I'm working\n");
	struct Node *root;
	root = new_node("hh");
	printf("%s\n", root -> data);
	//preorder(root);

	insert_node(root, argv[1]);
	insert_node(root, argv[1]);

	print_preorder(root);
	print_postorder(root);
	print_inorder(root);

	free(root);
	return EXIT_SUCCESS;
}

static void print_inorder(struct Node* root) {
	inorder(root);
}

static void print_preorder(struct Node* root){
	preorder(root);
}

static void print_postorder(struct Node* root){
	postorder(root);
}
