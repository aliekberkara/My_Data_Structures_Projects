#include <stdio.h>
#include <stdlib.h>

struct Index{
	int value;
	struct Index* next;
};

struct Index* hash[10], *temp;

//-----------------------------

void InsertElement(int number){
	int key;
	key = number % 10;
	struct Index* newNode = (struct Index*) malloc(sizeof(struct Index));
	newNode->value = number;
	newNode->next = NULL;
	if(hash[key] == NULL){
		hash[key] = newNode;
	}
	else{
		temp = hash[key];
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

//-----------------------------

void SearchElement(int number){
	int index;
	index = number%10;
	if(hash[index] == NULL){
		printf("\n-----------------------------------\nSearch Element Not Found!\n");
	}
	else{
		for(temp = hash[index]; temp != NULL; temp = temp->next){
			if(temp->value == number){
				printf("\n-----------------------------------\nSearch Element Found in the list at index %d\n", index);
				break;
			}
		}
		if(temp == NULL){
			printf("\n-----------------------------------\nSearch Element Not Found!\n");
		}
	}
}

//-----------------------------

void Display(){
	int i;
	for(i=0; i < 10; i++){
		printf("\n");
		if(hash[i] == NULL){
			printf("%d |", i);
			continue;
		}
		else{
			printf("%d | ", i);
			for(temp = hash[i]; temp != NULL; temp = temp->next){
				if(temp->next == NULL){
					printf("%d", temp->value);
					break;
				}
				printf("%d -> ", temp->value);
			}
		}
	}
}

//-----------------------------

int main()
{
	InsertElement(2);
	InsertElement(4);
	InsertElement(5);
	InsertElement(15);
	InsertElement(36);
	InsertElement(49);
	InsertElement(92);
	Display();
	SearchElement(5);
}
