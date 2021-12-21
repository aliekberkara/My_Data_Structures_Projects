#include <stdio.h>
#include <stdlib.h>

int Sum(int number){
	if(number == 1){
		return 1;
	}
	return number + Sum((number-1));
}

int main()
{
	int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    printf("---------------------------\nSum of numbers from 1 to %d: %d\n---------------------------", number, Sum(number));
    return 0;
}
