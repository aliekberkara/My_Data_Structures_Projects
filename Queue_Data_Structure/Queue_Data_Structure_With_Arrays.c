#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int array[SIZE], front = -1, rear = -1;

//---------------------------------

void Enqueue(int number){
	if(rear >= SIZE-1){
		printf("\n------------------------------\nThe Queue Is Full...");
		return;
	}
	if(front == -1){
		front++;
	}
	rear++;
	array[rear] = number;
}

//---------------------------------

int Dequeue(){
	if(front > rear || front == -1){
		printf("\n------------------------------\nThere are no staff!");
		return;
	}
	if(front == rear){
		front = -1;
		rear = -1;
		return;
	}
	if(rear >= SIZE-1){
		rear--;
	}
	int temp = array[front];
	front++;
	return temp;
}

//---------------------------------

void PrintQueue(){
	printf("\n------------------------------\n");
	if(front > rear || front == -1){
		printf("");
		return;
	}
	else{
		for(int i = front; i <= rear; i++){
			if(i == rear){
				printf("%d", array[i]);
				break;
			}
			printf("%d <= ", array[i]);
		}
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
