#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int array[SIZE], front = -1, rear = -1;

//---------------------------------

void Enqueue(int number){
	if((front == 0 && rear == SIZE-1) || (rear+1 == front)){
		printf("\n---------------------------------\nThe Queue Is Full.");
		return;
	}

	if(front == -1){
		front++;
	}
	rear = (rear + 1) % SIZE;
	array[rear] = number;
}

//---------------------------------

int Dequeue(){
	if(front == -1){
		printf("\n---------------------------------\nThere are no staff!");
		return -1;
	}
	if(front == rear){
		front = -1;
		rear = -1;
		return -1;
	}
	front = (front + 1) % SIZE;
	return -1;
}

//---------------------------------

void PrintQueue(){
	printf("\n------------------------------\n");
	int i;
	if(front == -1){
		printf(" ");
		return;
	}
	else{
		for(i = front; i != rear; i = (i+1)%SIZE){
			printf("%d <= ", array[i]);
		}
		printf("%d", array[i]);
	}
}

//---------------------------------

int main()
{
	int choice, number;
    while(1){
		printf("\n\n-----------------MENU-----------------\n0) Exit\n1) Print Queue\n2) Enqueue\n3) Dequeue\n\nChoose One: ");
		scanf("%d", &choice);
		if(choice == 0){
			printf("\n------------------------------\nExit is in progress...\n------------------------------\n");
			break;
		}
		else if(choice == 1){
			PrintQueue();
		}
		else if(choice == 2){
			printf("Enter a number: ");
			scanf("%d", &number);
			Enqueue(number);
		}
		else if(choice == 3){
			Dequeue();
		}
    }
    return 0;
}
