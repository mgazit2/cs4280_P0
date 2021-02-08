/* main.c */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "node.h"
#include "traversals.h"
#include "tree.h"

#define BUFFER 80

/* Prototypes */
static void build_tree(struct Node* root, char** array);
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
 	 * c-reading-file-and-splitting-with-strtok-into-an-array/46513747
	 * though familiar with the existence of strtok, I did not know how to
 	 * implement it into my program. The below code segment is taken from the
 	 * above stackoverflow link and bits of the man page */ 	
	FILE *finput;
	char *str = malloc(BUFFER * sizeof(char));	
	int counter = 0;
	char *tokenArray[100];
	int i = 0;
	int n; // final size of the array after file is read

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
	/* End stackoverflow segment */
	
	n = sizeof(tokenArray) / sizeof(*tokenArray);
	printf("%d\n", n);
	//char x[30];
	printf("I'm working\n");
	struct Node *root;
	root = new_node(tokenArray[0]);
	
	printf("%s\n", root -> data);
	//preorder(root);
	/*i = 1;
	for (; i < n; i++) {
		if (tokenArray[i] == NULL)
			break;
		insert_node(root, tokenArray[i]);	
	}*/

	//insert_node(root, tokenArray[1]);
	//insert_node(root, tokenArray[2]);


	build_tree(root, tokenArray);
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

static void build_tree(struct Node* root, char** array) {
	char* a;
	int i = 1;
	int n = sizeof(array) / sizeof(array[0]);
	printf("Here!");
        for (; i < n; i++, array++) {
                a = array[i];
		if (a == NULL)
                        break;
                insert_node(root, a);
        }
}
