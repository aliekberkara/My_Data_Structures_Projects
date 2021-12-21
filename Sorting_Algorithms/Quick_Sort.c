#include <stdio.h>
#include <stdlib.h>

/*
In the Quick Sort Algorithm, a random element is selected at each step.
Then, by traversing the array from beginning to end, the smaller ones are thrown to the left and the larger ones to the right.
Thus, all numbers smaller than the selected element are on the left, and large numbers are on the right.
*/

void Quick_Sort(int first, int end, int array[end+1]){
	int *pivot, i, j, temp;

	if(first < end){
		pivot = array+end;
		i = first;
		j = end;
		while(i < j){
			while(*(array+i) <= *pivot && i < end){
				i++;
			}
			while(*(array+j) > *pivot){
				j--;
			}
			if(i < j){
				temp = *(array+i);
				*(array+i) = *(array+j);
				*(array+j) = temp;
			}
		}
		temp = *pivot;
		*pivot = *(array+j);
		*(array+j) = temp;

		Quick_Sort(first, j-1, array);
		Quick_Sort(j+1, end, array);
	}


}

int main() {
    int number, *array, i;
    printf("Enter the Number of Elements of the Array: ");
    scanf("%d", &number);

    array = (int *) calloc(number, sizeof(int));
    printf("---------------------------\n");

    printf("Enter elements of the array: \n");
    for(i = 0; i < number; i++) {
        scanf("%d", (array+i));
    }
    printf("---------------------------\n");
    for(i = 0; i < number; i++) {
        printf("%d ", *(array+i));
    }
    printf("\n---------------------------\n");

    Quick_Sort(0, number-1, array);

	for(i = 0; i < number; i++) {
        printf("%d ", *(array+i));
    }
    printf("\n---------------------------");
    free(array);
    return 0;
}
