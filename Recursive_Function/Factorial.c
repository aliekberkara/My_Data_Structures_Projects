#include <stdio.h>
#include <stdlib.h>

int Factorial(int number){
	if(number == 1){
		return 1;
	}
	return number * Factorial(number-1);
}

int main()
{
	int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    printf("--------------------------\n%d! = %d\n--------------------------", number, Factorial(number));
    return 0;
}
