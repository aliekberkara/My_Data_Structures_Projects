#include <stdio.h>
#include <stdlib.h>

int Fibonacci(int number){
	if(number <= 1){
		return number;
	}
	return Fibonacci(number-1) + Fibonacci(number-2);
}

int main()
{
	int number;
    printf("Enter a number: ");
    scanf("%d", &number);

	printf("Element %d ==> %d", number, Fibonacci(number));
	return 0;
}
