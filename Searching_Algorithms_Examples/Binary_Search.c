#include <stdio.h>
#include <stdlib.h>

/*
In order to use binary search, the data must be in order. In binary search, the middle of the dataset is searched.
If the value we are looking for is less than the middle value, the search continues from the small side, that is, from the left side,
and if it is larger, from the right side. This process is also applied to small pieces until the sought value is found.
Thus, we eliminate half of the dataset in each search.
*/

int main()
{
	int number, *array, i, j, temp, median, search, first, end;
    printf("Enter the Number of Elements of the Array: ");
    scanf("%d", &number);

    array = (int *) calloc(number, sizeof(int));
    printf("---------------------------\n");

    printf("Enter elements of the array: \n");
    for(i = 0; i < number; i++){
		scanf("%d", (array+i));
    }
    printf("---------------------------\n");

	for(i = 0; i < number-1; i++){
		for(j = 0; j < number-i-1; j++){
			if(*(array+j) > *(array+j+1)){
				temp = *(array+j);
				*(array+j) = *(array+j+1);
				*(array+j+1) = temp;
			}
		}
	}

	for(i = 0; i < number; i++){
		printf("%d ", *(array+i));
    }
    printf("\n---------------------------\n");

    printf("Enter the Number to Search: ");
    scanf("%d", &search);


    printf("---------------------------\n");

	first = 0;
	end = number-1;
    median = (first+end)/2;

    while(first <= end){
		if(*(array+median) < search){
			first = median+1;
		}
		else if(*(array+median) == search){
			printf("The number %d is in the %d. row.", search, median+1);
			break;
		}
		else{
			end = median-1;
		}
		median = (first+end)/2;
    }
    if(first>end){
		printf("Not Found Number.");
    }
	printf("\n---------------------------");
	free(array);

    return 0;
}
