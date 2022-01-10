#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
The most searched words in a search engine are kept in a bidirectional linked list containing a maximum of 20 records.
According to this;

--> Design the appropriate data structure that can keep the searched word and how many times it is searched.
--> Write a function that adds the newly searched record to the end of the linked list
if there is an empty place in the bidirectional linked list, and gives a warning if the linked list is full.
--> If there is a record in the linked list as the search is made,
write the code that increases the number of searches by one and
ensures that it is in the appropriate order in the bidirectional linked list.
In the linked list, the most searched record will be found first and the least searched record will be found last.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SearchEngine{

    char word[10];
    int counter;
    struct SearchEngine *next;
    struct SearchEngine *prev;

};


struct SearchEngine *head=NULL, *iterator, *tempa;
int size = 0;

void Swap(struct SearchEngine *a, struct SearchEngine *b){

    char word[10];
    strcpy(word, a->word);
    strcpy(a->word, b->word);
    strcpy(b->word, word);

	int temp = a->counter;
	a->counter = b->counter;
	b->counter = temp;

}

void Sort(){

	if(head==NULL){
        return;
    }

	int swapped;
    struct SearchEngine *temp1;
    struct SearchEngine *temp2 = NULL;

    do{
        swapped = 0;
        temp1 = head;

        do{

            if(temp1->counter < temp1->next->counter){

                Swap(temp1, temp1->next);
                swapped = 1;
            }

            temp1 = temp1->next;

        }while(temp1->next != head);

        temp2 = temp1;

    }while(swapped);
}

void AddSearching(char word[]){

	int kn = 0;

	if(size <= 20){

		if(size == 0){

			head=(struct SearchEngine*)malloc(sizeof(struct SearchEngine));
			head->next = head;
			head->prev = head;
			strcpy(head->word, word);
			size++;
			head->counter++;

		}

		else{

			iterator = head;

			do{

				if(strcmp(iterator->word, word) == 0){

					kn = 1;
					break;
				}

				iterator=iterator->next;

			}while(iterator!=head);

			if(kn==0){

				iterator = head->prev;

				tempa = (struct SearchEngine*)malloc(sizeof(struct SearchEngine));
				iterator->next = tempa;
				tempa->next=head;
				head->prev=tempa;
				strcpy(tempa->word, word);
				size++;
				tempa->counter++;

			}

			else if(kn==1){
				iterator->counter++;
				size++;
			}

		}
	}

	else{
		printf("Full...\n------------------------------\n");
	}

	Sort();


}


//---------------------------------

void PrintList(){
	struct SearchEngine* temp = head;
	while(temp->next != head){
		printf("\nWord: %s  Counter: %d\n------------------------------\n", temp->word, temp->counter);
		temp = temp->next;
	}
	printf("\nWord: %s  Counter: %d\n------------------------------\n", temp->word, temp->counter);
}

int main()
{
	AddSearching("ali");
	AddSearching("veli");
	AddSearching("kara");
	AddSearching("sinan");
	AddSearching("ali");
	AddSearching("kara");
	AddSearching("ali");
	AddSearching("deli");
	AddSearching("sinan");
	AddSearching("kara");
	AddSearching("ali");
	AddSearching("sinan");
	AddSearching("sinan");
	AddSearching("deli");
	AddSearching("ali");
	AddSearching("kara");
	AddSearching("kara");
	AddSearching("kara");
	PrintList();
    return 0;
}
