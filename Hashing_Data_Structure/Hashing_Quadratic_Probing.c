#include <stdio.h>
#include <stdlib.h>

//The number of elements of the array must be a prime number.

int array[11];

//------------------------------------

void Display(){
	printf("---------------------------\n");
	int i;
	for(i = 0; i < 11; i++){
		if(array[i] == 0){
			printf(" %d |\n", i);
			continue;
		}
		printf(" %d | %d\n", i, array[i]);
	}
}

//------------------------------------

int CalculateHash(int number){
	int key = number%11;
	return key;
}

//------------------------------------

void InsertElement(int number){
	int index = CalculateHash(number);
	if(array[index] == 0){
		array[index] = number;
	}
	else{
		int i;
		for(i = 0; i < 11; i++){
			int condition = array[(index + i*i)%11];
			if(condition == 0){
				array[(index+i*i) % 11] = number;
				return;
			}
		}
	}
}

//------------------------------------

void SearchElement(int number){
	int index = CalculateHash(number);
	if(array[index] == number){
		printf("\n-----------------------------------\nSearch Element Found in the list at index %d\n", index);
	}
	else{
		int temp = index;
		while(array[temp] != 0){
			temp = (temp+1)%11;
			if(temp == index){
				printf("\n-----------------------------------\nSearch Element Not Found!\n");
				return;
			}
			if(array[temp] == number){
				printf("\n-----------------------------------\nSearch Element Found in the list at index %d\n", temp);
				return;
			}
		}
		printf("\n-----------------------------------\nSearch Element Not Found!\n");

	}
}

//------------------------------------

int main()
{
   InsertElement(19);
   InsertElement(94);
   InsertElement(13);
   InsertElement(22);
   InsertElement(38);
   InsertElement(45);
   InsertElement(14);
   InsertElement(25);
   InsertElement(21);
   InsertElement(61);
   InsertElement(4);
   Display();
   SearchElement(21);
    return 0;
}
