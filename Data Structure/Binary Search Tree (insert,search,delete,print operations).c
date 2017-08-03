#include <stdio.h>
#include <string.h>
#include <stdlib.h>



struct node { 
	int value;
	node *left, *right;	
} *root = NULL;

node *newNode(int value) { 
	
	node *temp = (node*) malloc(sizeof(node));
	temp->value = value;
	temp->left = NULL;
	temp->right = NULL;
	return temp;	
	
}

node* add (node *tree, int value) { 
	if(tree==NULL) return tree = newNode(value);
	else if(tree->value>value) tree->left = add(tree->left, value);
	else tree->right = add(tree->right, value); 
	return tree;
	
}

void searchANode (node *tree, int value) { 
	if(tree==NULL) { 
		printf ("The value %d does not exist in the binary search tree.\n", value);
		return;
	}
	else if (tree->value==value) { 
		printf ("The value %d does exist in the binary search tree.\n", value);
		return;
	}
	else if(tree->value > value)  searchANode(tree->left, value);
	else searchANode (tree->right, value);
	return ;	
}

void inorderPrint (node *tree) { 
	
	if(tree==NULL) return;
	inorderPrint(tree->left);
	printf("%d ",tree->value);
	inorderPrint(tree->right);	
}

int inorderSuccessor(node *tree) { 
	
	if(tree->left!=NULL) inorderSuccessor(tree->left);
	return tree->value;
}

node* deleteANode(node *tree, int value) { 
	
	if(tree==NULL) { 
		printf ("The value %d does not exist in the binary search tree.\n", value);
	}
	else if (tree->value == value) { 
		if(tree->left==NULL) {
			node *temp = tree->right;
			free(tree);
			return temp;
			}
		else if (tree->right==NULL) tree = tree->left;
		else {
			tree->value=inorderSuccessor(tree->right);
			tree->right = deleteANode(tree->right, tree->value);
		}
	}
	else if (tree->value>value) tree->left = deleteANode(tree->left, value);
	else tree->right = deleteANode(tree->right, value);	
	return tree;
}


int main() { 
	
	
	printf ("Enter 1 to add a number in tree,\nEnter 2 to search a number,\nEnter 3 to delete a number,\nEnter 4 to print the tree in inorder traversal,\nEnter 0 to exit the program.\n");
	
	
	int x,y;
	while (true) { 
		scanf ("%d",&x);
		
		if(x==1) { 
			printf ("Enter the number to add in the tree: ");
			scanf ("%d", &y);
			root = add(root, y);			
		}
		else if (x==2) { 
			printf ("Enter the number to search in the tree: ");
			scanf ("%d", &y);
			searchANode(root, y);
		}
		else if (x==3) { 
			printf ("Enter the number to delete from the tree: ");
			scanf ("%d", &y);
			root = deleteANode(root, y);
		}
		else if(x==4) { 
			 printf("Inorder traversal of the tree \n");
			inorderPrint(root);
			printf ("\n");
		}
		else if(x==0) break;
		else { 
			printf ("You entered wrong number in input. Please try again.\n");
		}
		
	}

	
	
	
	return 0;
}
