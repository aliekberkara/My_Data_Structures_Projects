#include <stdio.h>
#include <stdlib.h>

int Binary(int number){
	if(number == 0){
		return 0;
	}
	return (number % 2) + (Binary(number/2) *10);
}

int main()
{
	int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    printf("%d ==> %d", number, Binary(number));
    return 0;
}
