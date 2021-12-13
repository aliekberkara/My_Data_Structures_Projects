#include <stdio.h>
#include <stdlib.h>

/*
It basically proceeds by making a comparison between two consecutive elements.
For example, if the first element is greater than the second in a number sequence to be ordered from smallest to largest,
these two numbers are swapped between themselves. The comparison then continues with the next number.
It is not preferred primarily because it works slowly in large arrays. While programming the bubble sorting algorithm,
we need to assign the number to be changed to a temporary variable for the swap function to be used in case of swapping
two numbers compared. Otherwise, this number value will be lost in memory.
*/

int main()
{
	int number, *array, i, j, temp;
    printf("Enter the Number of Elements of the Array: ");
    scanf("%d", &number);

    array = (int *) calloc(number, sizeof(int));
    printf("---------------------------\n");

    printf("Enter elements of the array: \n");
    for(i = 0; i < number; i++){
		scanf("%d", (array+i));
    }
    printf("---------------------------\n");
	for(i = 0; i < number; i++){
		printf("%d ", *(array+i));
    }
    printf("\n---------------------------\n");

	for(i = 0; i < number-1; i++){
		for(j = 0; j < number-i-1; j++){
			if(*(array+i) > *(array+i+1)){
				temp = *(array+i);
				*(array+i) = *(array+i+1);
				*(array+i+1) = temp;
			}
		}
	}

	for(i = 0; i < number; i++){
		printf("%d ", *(array+i));
    }
    printf("\n---------------------------");
    return 0;
}
