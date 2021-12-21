#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int size;
int array[100];
int control[100];


//-------------------------------------------------

void AddElements(int add, int index){
	int i;
	size++;
	if(index < 1 || index > size+1){
		printf("--------------------------------\nInvalid Index Number!!!\n");
		size--;
		return;
	}
	for(i = (size-1); i >= index-1; i--){
		array[i+1] = array[i];
	}
	array[index-1] = add;

}

//-------------------------------------------------

void PrintArray(int highlight){
	printf("--------------------------------\n");
	for(int i = 0; i < size; i++){
		if(highlight > size){
			break;
		}
		else{
			if(i+1 == highlight){
				printf("%d | %d <======\n", i+1, array[i]);
			}
			else{
				printf("%d | %d\n", i+1, array[i]);
			}
		}

	}
}

//-------------------------------------------------

int PositionControl(int position){
	for(int i = 0; i < size; i++){
		if(control[i] == position){
			return 1;
		}
	}
	return 0;
}

//-------------------------------------------------

void AddRandom(int number){
	int position, add, counter = 0, isFull;
	for(int i = 0; i < number; i++){
		add = rand() %100;
		if(add == 0){
			while(add == 0){
				add = rand() %100;
			}
		}
		position = rand() %size;
		isFull = PositionControl(position);
		if(isFull == 1){
			while(isFull == 1){
				position = rand() %size;
				isFull = PositionControl(position);
			}
		}
		array[position] = add;
		control[counter] = position;
		counter++;
	}
}

//-------------------------------------------------

void DeleteElement(int element){
	int i;

	if(element < 1 || element > size){
		printf("\n------------------------------\nThere is not a such index!\n");
	}
	else{
		for(i = 0; i < size-1; i++){
			if(i >= (element-1)){
				array[i] = array[i+1];
			}
		}
		array[i] = '\0';
		size--;
	}
}

//-------------------------------------------------

int SearchElement(int element){
	int i;
	for(i = 0; i < size; i++){
		if(array[i] == element){
			return i;
		}
	}
	return -1;
}

//-------------------------------------------------

void ReverseArray(){
	int i, j, temp;
	for(i = 0, j = size-1; i < j; i++, j--){
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}

//-------------------------------------------------

void CreateMatrix(int number, int matrix[number][number]){
	int i, j;
	printf("--------------------------------\n");
	for(i = 0; i < number; i++){
		for(j = 0; j < number; j++){
			matrix[i][j] = rand() %10;
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n--------------------------------\n");
}

//-------------------------------------------------

int main()
{
	int choice, index, number, control1 = 0;
	srand(time(0));
	printf("Enter size of array: ");
	scanf("%d", &size);

	for(int i = 0; i < size; i++){
		control[i] = -1;
	}

	//-------------------------------------------------

	while(1){

		printf("\n------------MENU--------------\n1) Add To Array\n2) Add Random To Array\n3) Delete Element\n");
		printf("4) Search Element\n5) Reverse Array\n6) Create Matrix\n\nChoose one: ");
		scanf("%d", &choice);
		if(choice == 1){
			printf("Enter a number: ");
			scanf("%d", &number);
			printf("Enter Sequence Number: ");
			scanf("%d", &index);
			AddElements(number, index);
			PrintArray(index);
		}

		//-------------------------------------------------

		else if(choice == 2){
			if(control1 == 0){
				printf("Enter the number of elements to add: ");
				scanf("%d", &number);
				AddRandom(number);
				PrintArray(0);
			}
			else{
				printf("This is a one-time operation.");
			}
			control1++;
		}

		//-------------------------------------------------

		else if(choice == 3){
			printf("Enter the sequence of the number to be deleted: ");
			scanf("%d", &index);
			DeleteElement(index);
			PrintArray(0);
		}

		//-------------------------------------------------

		else if(choice == 4){
			printf("Enter the element to search: ");
			scanf("%d", &number);
			index = SearchElement(number);
			if(index == -1){
				printf("Element Not Found in Array.");
			}
			else{
				PrintArray((index+1));
			}
		}

		//-------------------------------------------------

		else if(choice == 5){
			ReverseArray();
			PrintArray(0);
		}

		//-------------------------------------------------

		else if(choice == 6){
			printf("Enter a number: ");
			scanf("%d", &number);
			int matrix[number][number];
			CreateMatrix(number, matrix);
		}

	}

}
