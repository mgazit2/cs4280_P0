/* traversals.c
 * Matan Gazit */
#include "node.h"
#include <stdlib.h>
#include <stdio.h>

void inorder(struct Node *root) {
	FILE *printFile;
        printFile = fopen("output.inorder", "a");
        if (printFile == NULL) {
                printf("File could not be opened...\n");
                exit(1);
        }
	if (root != NULL) {
		inorder(root -> left);
		//printf("%s\n", root -> data);
		fprintf(printFile, "%s ", root -> data);
		fclose(printFile);
		inorder(root -> right);
	}
}

void preorder(struct Node *root) {
        FILE *printFile;
	printFile = fopen("output.preorder", "a");
	if (printFile == NULL) {
		printf("File could not be oppened...\n");
		exit(1);
	}
	if (root != NULL) {
		//printf("%s\n", root -> data);
		fprintf(printFile, "%s ", root -> data);
		fclose(printFile);
                preorder(root -> left);
                preorder(root -> right);
        }
}

void postorder(struct Node *root) {
	FILE *printFile;
        printFile = fopen("output.postorder", "a");
        if (printFile == NULL) {
                printf("File could not be oppened...\n");
                exit(1);
        }
        if (root != NULL) {
                postorder(root -> left);
                postorder(root -> right);
		//printf("%s\n", root -> data);
		fprintf(printFile, "%s ", root -> data);
        }
}
