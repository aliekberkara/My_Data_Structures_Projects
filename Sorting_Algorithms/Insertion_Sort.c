#include <stdio.h>
#include <stdlib.h>

/*
In the Insertion Sort Algorithm, starting from the second element,
large elements are shifted to the right in the array by comparing the element with the previous elements.
Thus, the currently listed element is placed in the appropriate position.
That is, considering that the algorithm sorts from smallest to largest,
it chooses the second element of the number array as its key element.
This key element starts from the previous element and compares the number selected as the key with all the numbers before it.
It changes places with any number greater than itself.
When it encounters a smaller number than itself, the displacement operation ends.
Then, key number selection and all subsequent operations continue until the last element of the array.
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

    for(i = 1; i < number; i++){
		for(j = i; j >= 1; j--){
			if(*(array+j) < *(array+j-1)){
				temp = *(array+j);
				*(array+j) = *(array+j-1);
				*(array+j-1) = temp;
			}
		}
    }

	for(i = 0; i < number; i++){
		printf("%d ", *(array+i));
    }
    printf("\n---------------------------");
    free(array);
    return 0;
}
