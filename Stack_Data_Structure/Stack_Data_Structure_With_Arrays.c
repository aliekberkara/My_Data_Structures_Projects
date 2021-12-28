#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int size, array[10], top = -1;

//-----------------------------

bool IsFull() {
    if(top == size-1) {
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

void Push(int number) {
    bool full = IsFull();
    if(full == true) {
        printf("\n-------------------------\nStackoverflow.");
        return;
    }
    top++;
    array[top] = number;
}

//-----------------------------

void Pop() {
    bool empty = IsEmpty();
    if(empty == true) {
        printf("\n-------------------------\nThere are no staff!");
        return;
    }
    top--;
}

//-----------------------------

int Peek() {
    return array[top];
}

//-----------------------------

void PrintStack() {
    printf("\n------------------------\n");
    for(int i = top; i>=0; i--) {
        printf("|_%d_|\n", array[i]);
    }
}

//-----------------------------

int main() {
    int choice, number;
    printf("Enter a number: ");
    scanf("%d", &size);
    while(true) {
        printf("\n\n-------------MENU-------------\n\n0) Exit\n1) Print Stack\n2) Push\n3) Pop\n4) Peek\n\nChoose One: ");
        scanf("%d", &choice);

        if(choice == 0) {
            printf("------------------------------\nExit is in progress...\n------------------------------");
            break;
        } else if(choice == 1) {
            PrintStack();
        } else if(choice == 2) {
            printf("\n-------------------------\nEnter a number: ");
            scanf("%d", &number);
            Push(number);
        } else if(choice == 3) {
            Pop();
        } else if(choice == 4) {
            bool empty = IsEmpty();
            if(empty == true) {
                printf("\n-------------------------\nThere are no staff!");
            } else {
                printf("\n-------------------------\nTop Element: %d", Peek());
            }
        }
    }



    return 0;
}
