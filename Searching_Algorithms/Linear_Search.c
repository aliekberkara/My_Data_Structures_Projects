#include <stdio.h>
#include <stdlib.h>

/*
This search, also called Sequential Search, is literally searching for data by looking at the searched ones one by one.
*/

int main()
{
   int number, *array, i, search, Is_There;
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
    };

	printf("\n---------------------------\n");

    printf("Enter the Number to Search: ");
    scanf("%d", &search);


    printf("---------------------------\n");

    Is_There = 0;
    for(i = 0; i < number; i++){
		if(*(array+i) == search){
			Is_There = 1;
			break;
		}
    }
    if(Is_There == 1){
		printf("The number %d is in the %d. row.", *(array+i), i+1);
    }
    else{
		printf("Number Not Found.");
    }
    printf("\n---------------------------");
    free(array);
    return 0;
}
