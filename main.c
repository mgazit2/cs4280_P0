/* main.c */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "node.h"
#include "traversals.h"
#include "tree.h"

#define BUFFER 80

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

	/* https://stackoverflow.com/questions/46512315/
 	 * c-reading-file-and-splitting-with-strtok-into-an-array/46513747  */
	FILE *finput;
	char *str = malloc(BUFFER * sizeof(char));	
	int counter = 0;
	char *tokenArray[100];
	int i = 0;
	//int j = 0;	
	//char *token;

	finput = fopen(argv[1], "r");
	while (fgets(str, BUFFER, finput) != NULL) {
		tokenArray[0] = strtok(str, " ");
		for (i = 1; i < sizeof(tokenArray) / sizeof(tokenArray[0]); i++) {
			if ((tokenArray[i] = strtok(NULL, " ")) == NULL)
				break;
		}
		counter = i;
	
		for (i = 0; i < counter; i++) {
			printf("%s\n", tokenArray[i]);
		}
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
	fclose(finput);
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
