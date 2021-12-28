#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char word[20], reverse[20];
int top = -1;

//-----------------------------

bool IsFull() {
    if(top >= 49) {
        return true;
    }
    return false;
}

//-----------------------------

bool IsEmpty() {
    if(top == -1) {
        return true;
    }
    return false;
}

//-----------------------------

void Push(char character) {
    bool full = IsFull();
    if(full == true) {
        printf("\n-------------------------\nStackoverflow.");
        return;
    }
    top++;
    reverse[top] = character;
}

//-----------------------------

char Pop() {
    bool empty = IsEmpty();
    if(empty == true) {
        printf("\n-------------------------\nThere are no staff!");
        return;
    }
    char character = reverse[top];
    top--;
    return character;
}

//-----------------------------

int main()
{
    printf("Enter a word: ");
    gets(word);

    printf("--------------------------\nWord: '%s'", word);

    for(int i = 0; i < strlen(word); i++){
		Push(word[i]);
    }

	for(int i = 0; i < strlen(word); i++){
		word[i] = Pop();
    }

	printf("\n\n--------------------------\nReversed Word: '%s'\n--------------------------", word);

    return 0;
}
