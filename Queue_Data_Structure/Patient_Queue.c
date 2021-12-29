#include <stdio.h>
#include <stdlib.h>

struct Patient{
    double ID;
    char name[20];
    char surname[20];
    int Priority;
    struct Patient* next;
};

struct Patient* front = NULL;
struct Patient* rear = NULL;

struct Patient* Create(){
    struct Patient* newPatient = (struct Patient*)malloc(sizeof(struct Patient));
    newPatient->next = NULL;

    return newPatient;
}

void EnQueue(struct Patient* Add_Patient)
{
    if(front == NULL)
    {
        front = Add_Patient;
        rear = Add_Patient;
    }
    else
    {
        if(Add_Patient->Priority> front->Priority)
        {
            struct Patient* second = front;
            front = Add_Patient;
            front->next = second;
            return;
        }
        else
        {
            struct Patient* temp = front;

            while(temp->next != NULL && Add_Patient->Priority < temp->next->Priority)
                temp = temp->next;
            if(temp->next == NULL)
            {
                rear->next = Add_Patient;
                rear = Add_Patient;
            }
            else
            {
                struct Patient* Next = temp->next;
                temp->next = Add_Patient;
                Add_Patient->next = Next;
            }
        }


    }
}

struct Patient* Dequeue()
{
    if(front == NULL)
    {
        printf("\n-----------------------------\nThere are no staff!");
        return NULL;
    }

    struct Patient* deleted = front;
    struct Patient* newFront = front->next;
    front = NULL;
    front = newFront;
    return deleted;
}

void PrintPatientQueue(){
	printf("\n------------------------------\n");
    if(front == NULL)
    {
        printf(" ");
        return;
    }

    struct Patient* temp = front;
    while(temp != NULL)
    {
        printf("%.0lf %s %s %d\n\n", temp->ID, temp->name, temp->surname, temp->Priority);
        temp = temp->next;
    }
}

int main()
{
   int choice;
   struct Patient* newPatient;
   while(1)
	{
		printf("\n\n-----------------MENU-----------------\n0) Exit\n1) Print Patient Queue\n2) Enqueue\n3) Dequeue\n\nChoose One: ");
		scanf("%d", &choice);
		if(choice == 0){
			printf("\n-----------------------------\nExit is in progress...\n-----------------------------\n");
			break;
		}
		else if(choice == 1){
			PrintPatientQueue();
		}
		else if(choice == 2){
            newPatient = Create();
            printf("Enter Patient ID: ");
            scanf("%lf", &newPatient->ID);
            printf("Enter Patient Name: ");
            scanf("%s", newPatient->name);
            printf("Enter Patient Surname: ");
            scanf("%s", newPatient->surname);
            printf("Enter Patient Priority: ");
            scanf("%d", &newPatient->Priority);

            EnQueue(newPatient);
		}
		else if(choice == 3){
			Dequeue();
		}
	}
}
