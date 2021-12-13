#include <stdio.h>
#include <stdlib.h>

/*
In the Selection Sort Algorithm, the first element of the array is considered the smallest,
then the smallest element in the array is searched, and when found, it is replaced with the first element;
then the second smallest element is searched among the remaining elements and replaced with the second element.
When this process is repeated until the last element of the array, the array is sorted from smallest to largest.
*/

int main()
{
    int number, *array, i, j, temp, *min;
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

    for(i = 0; i < number; i++){

		min = array+i;
		for(j = i; j < number; j++){
			if(*min > *(array+j)){
				temp = *(array+j);
				*(array+j) = *min;
				*min = temp;
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
