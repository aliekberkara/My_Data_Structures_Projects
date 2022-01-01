#include <stdio.h>
#include <stdlib.h>

struct Node{
	int number;
	struct Node* LeftChild;
	struct Node* RightChild;
};

struct Node* RootNode = NULL;

//----------------------------------

struct Node* CreateNode(int number){
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->number = number;
	newNode->LeftChild = NULL;
	newNode->RightChild = NULL;

	return newNode;
}

//----------------------------------

void InOrder(struct Node* node){
	if(node != NULL){
		InOrder(node->LeftChild);
		printf("%d ", node->number);
		InOrder(node->RightChild);
	}
}

//----------------------------------

struct Node* InsertNode(struct Node* root, int number){
	if(root == NULL){
		return CreateNode(number);
	}
	if(number < root->number){
		root->LeftChild = InsertNode(root->LeftChild, number);
	}
	if(number > root->number){
		root->RightChild = InsertNode(root->RightChild, number);
	}

	return root;
}

//----------------------------------

struct Node* SearchNode(struct Node* root, int number){
	if(root == NULL){
		printf("Tree is empty");
		return NULL;
	}
	if(number == root->number){
		printf("Searched Number: %d", root->number);
		return root;
	}
	else if(number > root->number){
		printf("Number Checked: %d\n\n", root->number);
		return SearchNode(root->RightChild, number);
	}
	else{
		printf("Number Checked: %d\n\n", root->number);
		return SearchNode(root->LeftChild, number);
	}
}

//----------------------------------

struct Node* DeleteNode(struct Node* root, int number){
	struct Node* temp;

	if(root == NULL){
		printf("\n------------------------------\nThere are no staff!\n");
		return NULL;
	}

	if(RootNode->number == number && RootNode->LeftChild == NULL && RootNode->RightChild == NULL){
		RootNode = NULL;
		return RootNode;
	}

	if(number == root->number){
		if(root->LeftChild == NULL){
			temp = root->RightChild;
			root = NULL;
			return temp;
		}
		else if(root->RightChild == NULL){
			temp = root->LeftChild;
			root = NULL;
			return temp;
		}
		else{
			temp = root->RightChild;
			while(temp != NULL && temp->LeftChild != NULL){
				temp = temp->LeftChild;
			}

			root->number = temp->number;
			root->RightChild = DeleteNode(root->RightChild, temp->number);
		}
	}
	else if(number > root->number){
		root->RightChild = DeleteNode(root->RightChild, number);
	}
	else{
		root->LeftChild = DeleteNode(root->LeftChild, number);
	}
	return root;
}

//----------------------------------

int main()
{
	RootNode = InsertNode(RootNode, 20);
	InsertNode(RootNode, 30);
	InsertNode(RootNode, 40);
	InsertNode(RootNode, 29);
	InsertNode(RootNode, 16);
	InsertNode(RootNode, 8);
	InsertNode(RootNode, 32);
	InOrder(RootNode);
	printf("\n-----------------------------\n");
	SearchNode(RootNode, 8);
	printf("\n-----------------------------\n");
	DeleteNode(RootNode, 20);
	InOrder(RootNode);
	printf("\n-----------------------------\n");

    return 0;
}
