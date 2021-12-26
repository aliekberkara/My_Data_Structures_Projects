#include <stdio.h>
#include <stdlib.h>

struct Node{
	int number;
	struct Node* next;
	struct Node* prev;
};

struct Node* first = NULL;

//------------------------------------------------------

struct Node* Create(int number){

	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->number = number;
	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
}

//------------------------------------------------------

void PrintList(){
	struct Node* temp = first;

	while(temp!=NULL){
		if(temp->next == NULL){
			printf("%d", temp->number);
			break;
		}
		printf("%d -> ", temp->number);
		temp = temp->next;
	}

}

//------------------------------------------------------

void AddToLast(int number){
	struct Node* add = Create(number);
	if(first == NULL){
		first = add;
	}
	else{
		struct Node* temp = first;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = add;
		add->prev = temp;
	}
}

//------------------------------------------------------

void AddToFirst(int number){
	struct Node* add = Create(number);
	if(first == NULL){
		first = add;
	}
	else{
		struct Node* temp = first;
		first = add;
		first->next = temp;
		temp->prev = first;
	}
}

//------------------------------------------------------

void AddBetween(int number, int position){
	struct Node* add = Create(number);
	int control = 0;

	if(first == NULL && position > 0){
		printf("\n------------------------------\nThere is no such sequence number\n------------------------------\n");
		return;
	}

	if(position == 0){
		AddToFirst(number);
		return;
	}
	else{
		struct Node* temp = first;
		int counter = 0;

		while(temp != NULL){
			if(counter == position-1){
				control = 1;
				break;
			}
			temp = temp->next;
			counter++;
		}
		if(control == 0){
			printf("\n------------------------------\nThere is no such sequence number\n------------------------------\n");
			return;
		}
		if(temp->next == NULL){
			AddToLast(number);
			return;
		}
		struct Node* tempNext = temp->next;
		temp->next = add;
		add->prev = temp;
		add->next = tempNext;
		tempNext->prev = add;
	}
}

//------------------------------------------------------

void DeleteFromLast(){
	struct Node* temp = first;
	if(first == NULL){
		printf("\n------------------------------\nThere are no staff!");
		return;
	}
	if(first->next == NULL){
		first = NULL;
		return;
	}
	while(temp->next->next != NULL){
		temp = temp->next;
	}
	temp->next = NULL;
}

//------------------------------------------------------

void DeleteFromFirst(){
	if(first == NULL){
		printf("\n------------------------------\nThere are no staff!");
		return;
	}
	if(first->next == NULL){
		first = NULL;
		return;
	}
	struct Node* second = first->next;
	first = second;

}

//------------------------------------------------------

void DeleteFromBetweenByPosition(int position){
	struct Node* temp = first;
	int counter = 0, control = 0;

	if(first == NULL){
		printf("\n------------------------------\nThere are no staff!");
		return;
	}
	if(position == 0){
		first = first->next;
		return;
	}
	while(temp != NULL){
		if(counter == position-1){
			control = 1;
			break;
		}
		temp = temp->next;
		counter++;
	}
	if(control == 0){
		printf("\n------------------------------\nThere are no staff!\n------------------------------\n");
		return;
	}
	if(temp->next == NULL){
		printf("\n------------------------------\nThere are no staff!\n------------------------------\n");
		return;
	}

	struct Node*temp1 = temp->next->next;
	if(temp1 == NULL){
		temp->next = temp1;
		return;
	}
	temp->next = temp1;
	temp1->prev = temp;
}

//------------------------------------------------------

void DeleteFromBetweenByElement(int element){
	int control = 0;

	if(first == NULL){
		printf("\n------------------------------\nThere are no staff!");
		return;
	}
	if(first->number == element){
		first = first->next;
		return;
	}
	struct Node* temp = first;
	while(temp->next != NULL){
		if(temp->next->number == element){
			control = 1;
			break;
		}
		temp = temp->next;
	}
	if(control == 0){
		printf("\n------------------------------\nThe element you are looking for was not found.");
		return;
	}

	struct Node* temp1 = temp->next->next;
	if(temp1 == NULL){
		temp->next = NULL;
		return;
	}
	temp->next = temp1;
	temp1->prev = temp;

}

//------------------------------------------------------

struct Node* ReverseList(struct Node* temp){

	if(temp == NULL){
		return;
	}
	if(temp->next == NULL){
		first = temp;
		return temp;
	}

	struct Node* node = ReverseList(temp->next);
	node->next = temp;
	temp->next = NULL;
	return temp;
}

//------------------------------------------------------

int main()
{
    int choice, number, position;

	while(1){
		printf("\n\n-------------MENU-------------\n\n0) Exit\n1) Print List\n2) Add To End\n3) Add To First\n4) Add Between\n"
				"5) Delete From End\n6) Delete From First\n7) Delete from Between by Position\n"
				"8) Delete From Between by Element\n9) Reverse List\n\nChoose One: ");
		scanf("%d", &choice);

		if(choice == 0){
			printf("------------------------------\nExit is in progress...\n------------------------------");
			break;
		}
		else if(choice == 1){
			PrintList();
		}
		else if(choice == 2){
			printf("Enter a number: ");
			scanf("%d", &number);
			AddToLast(number);
		}
		else if(choice == 3){
			printf("Enter a number: ");
			scanf("%d", &number);
			AddToFirst(number);
		}
		else if(choice == 4){
			printf("Enter a number: ");
			scanf("%d", &number);
			printf("Enter the Sequence Number of the Element to be Add: ");
			scanf("%d", &position);
			AddBetween(number, (position-1));
		}
		else if(choice == 5){
			DeleteFromLast();
		}
		else if(choice == 6){
			DeleteFromFirst();
		}
		else if(choice == 7){
			printf("Enter the Sequence Number of the Element to be Delete: ");
			scanf("%d", &position);
			DeleteFromBetweenByPosition(position-1);
		}
		else if(choice == 8){
			printf("Enter the Element to be Delete: ");
			scanf("%d", &number);
			DeleteFromBetweenByElement(number);
		}
		else if(choice == 9){
			ReverseList(first);
		}
	}
    return 0;
}
