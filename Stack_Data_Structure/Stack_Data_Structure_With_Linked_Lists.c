#include <stdio.h>
#include <stdlib.h>

struct Node{
	int number;
	struct Node* next;
};

struct Node* top = NULL;

//---------------------------

void Push(int number){
	struct Node* add = (struct Node*) malloc(sizeof(struct Node));
	add->number = number;
	add->next = top;
	top = add;
}

//---------------------------

void Pop(){
	if(top == NULL){
		printf("\n---------------------------\nThere are no staff!");
		return;
	}
	struct Node* temp = top->next;
	if(top->next == NULL){
		top = NULL;
	}
	else{
		top = temp;
	}
}

//---------------------------

int Peek(){
	return top->number;
}

//---------------------------

void PrintStack(){
	struct Node* temp = top;
	printf("------------------------------\n");
	while(temp != NULL){
		printf("|_%d_|\n", temp->number);
		temp = temp->next;
	}
}

//---------------------------

int main()
{
	int choice, number;
	while(1){
		printf("\n\n-------------MENU-------------\n\n0) Exit\n1) Print Stack\n2) Push\n3) Pop\n4) Peek\n\nChoose One: ");
		scanf("%d", &choice);
		if(choice == 0){
			printf("---------------------------\nExit is in progress...\n---------------------------");
			break;
		}
		else if(choice == 1){
			PrintStack();
		}
		else if(choice == 2){
			printf("------------------------------\n");
			printf("Enter a number: ");
			scanf("%d", &number);
			Push(number);
		}
		else if(choice == 3){
			Pop();
		}
		else if(choice == 4){
			if(top == NULL){
				printf("\n---------------------------\nThere are no staff!");
			}
			else{
				printf("\n---------------------------\nTop Element: %d", Peek());
			}
		}
	}

	return 0;
}
