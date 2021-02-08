/* main.c */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "node.h"
#include "traversals.h"
#include "tree.h"

#define BUFFER 100
#define SIZE 10

/* Prototypes */
static void build_tree(struct Node* root, char** array);
static void print_inorder(struct Node* root);
static void print_preorder(struct Node* root);
static void print_postorder(struct Node* root);
/* End Prototypes */

int main(int argc, char *argv[]) {
	//Input validation
	char* word[SIZE];
	int c;
	if (argc == 1) {
		for (c = 0; c < SIZE; c++) {
			word[c] = malloc(BUFFER * sizeof(char));
			printf("Enter a word: ");
			scanf("%99s", word[c]); // %99s avoids overflow	
		}

		struct Node *root;
		root = new_node(word[0]);

		build_tree(root, word);
		print_inorder(root);
		print_preorder(root);
		print_postorder(root);

		free(root);
			
		printf("Number of arguments is %d\n", argc-1);
		printf("Please call this process w/ at least 1 string file\n");
		return EXIT_SUCCESS;
	}
	else {
		/* https://stackoverflow.com/questions/46512315/
	 	 * c-reading-file-and-splitting-with-strtok-into-an-array/46513747
		 * though familiar with the existence of strtok, I did not know how to
	 	 * implement it into my program. The below code segment is taken from the
	 	 * above stackoverflow link and bits of the man page */ 	
		FILE *finput;
		char *str = malloc(BUFFER * sizeof(char));	
		//int counter = 0;
		char *tokenArray[100];
		int i = 0;
		//int n = 0; // final size of the array after file is read

		finput = fopen(argv[1], "r");
		while (fgets(str, BUFFER, finput) != NULL) {
			tokenArray[0] = strtok(str, " ");
			for (i = 1; i < sizeof(tokenArray) / sizeof(tokenArray[0]); i++) {
				if ((tokenArray[i] = strtok(NULL, " ")) == NULL)
					break;
			}
			//counter = i;
		}	
		/* End stackoverflow segment */

		struct Node *root;
		root = new_node(tokenArray[0]);
		
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
	printf("Did nothing.");
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
	char** a;
	//int i = 1;
	//int n = sizeof(array) / sizeof(array[0]);
	printf("In build_tree()\n");
        // Flip through the library
	for (a = array + 1; *a != NULL; a++) {
                //a = array[i];
		if (a == NULL)
                        break;
                insert_node(root, *a);
        }
}
