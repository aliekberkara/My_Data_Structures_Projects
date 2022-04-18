#include <stdio.h>
#include <stdlib.h>

#define INF 999

typedef struct{
	int value;
	struct Node* next;
}Node;

Node* nodeList[10], *destinationList[10], *weightList[10], *temp, *temp1, *temp2;
int Path[100][100], node[100], dest[100], weight[100], length, control = 0;

//----------------------------------------

int InsertNodeList(int node, int dest, int weight){

	int i = 0;
	Node* newNode = (Node*) malloc(sizeof(Node));
	Node* newDest = (Node*) malloc(sizeof(Node));
	Node* newWeight = (Node*) malloc(sizeof(Node));

	newWeight->value = weight;
	newNode->value = node;
	newDest->value = dest;
	newNode->next = NULL;
	newDest->next = NULL;
	newWeight->next = NULL;

	while(nodeList[i] != NULL){
		temp = destinationList[i];
		temp1 = weightList[i];
		temp2 = nodeList[i];
		temp2->next = temp;
		if(nodeList[i]->value == node){
			while(temp->next != NULL && temp1->next != NULL){
				temp = temp->next;
				temp1 = temp1->next;
			}
			temp->next = newDest;
			temp1->next = newWeight;
			return;
		}
		i++;
	}
	nodeList[i] = newNode;
	destinationList[i] = newDest;
	weightList[i] = newWeight;
	temp = destinationList[i];
	temp1 = weightList[i];
	temp2 = nodeList[i];
	temp2->next = temp;
	length = i+1;
}

//----------------------------------------

void InsertNodeMatrix(int size){
	int i = 0, j = 0;

	while(i < size){
		j = 0;
		while(j < size){
			if(i == j){
				Path[i][j] = 0;
			}
			else{
				Path[i][j] = INF;
			}
			j++;
		}
		i++;
	}

	if(control == 1){
		i = 0, j = 0;
		while(i < size){
			Path[node[i]-1][dest[i]-1] = 1;
			i++;
		}
	}
	else{
		i = 0, j = 0;
		while(i < size){
			Path[node[i]-1][dest[i]-1] = weight[i];
			i++;
		}
	}
}

//----------------------------------------

void DisplayList(int size){
	int i = 0;
	printf("\n\n");
	while(i<size){
		temp2 = nodeList[i];
		temp1 = weightList[i];
		printf("%d | ", temp2->value);
		temp2 = temp2->next;
		while(temp2->next != NULL || temp1->next != NULL){
			printf("%d(%d) -> ", temp2->value, temp1->value);
			temp2 = temp2->next;
			temp1 = temp1->next;
		}
		printf("%d(%d)\n", temp2->value, temp1->value);
		i++;
	}
	printf("\n\n----------------------------------------\n\n");

}

//----------------------------------------

void DisplayMatrix(int size){
	int i = 0, j = 0;
	printf("\n\n   ");

	while(i<size){
		printf("%d ", i+1);
		i++;
	}
	i = 0;
	printf("\n   ");
	while(i<size){
		printf("_ ");
		i++;
	}
	i = 0;
	printf("\n");
	while(i<size){
		j = 0;
		printf("%d|", i+1);
		while(j<size){
			if(Path[i][j] == INF){
				printf(" -");
			}
			else{
				printf(" %d", Path[i][j]);
			}
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n\n----------------------------------------");
}

//----------------------------------------

void isConnected(int graph[100][100], int size){
	int i = 0, j = 0, k = 0;
	while(k < size){
		i = 0;
		while(i < size){
			j = 0;
			while(j < size){
				if(graph[i][k] + graph[k][j] < graph[i][j]){
					graph[i][j] = graph[i][k] + graph[k][j];
				}
				j++;
			}
			i++;
		}
		k++;
	}

	printf("\n\n\n   ");
	i = 0;
	while(i<size){
		printf("%d ", i+1);
		i++;
	}
	i = 0;
	printf("\n   ");
	while(i<size+2){
		printf("_ ");
		i++;
	}
	printf("\n");
	i = 0, j = 0;
	while(i < size){
		j = 0;
		printf("%d| ", i+1);
		while(j < size){
			if(graph[i][j] == INF){
				printf("- ");
			}
			else{
				printf("%d ", graph[i][j]);
			}

			j++;
		}
		printf("\n");
		i++;
	}

	printf("\n\n");
	i = 0, j = 0;
	while(i < size){
		j = 0;
		while(j < size){
			if(graph[i][j] == INF){
				printf("The Graph Is Not a Connected Graph.\n\n----------------------------------------");
				return;
			}
			j++;
		}
		i++;
	}
	printf("The Graph Is a Connected Graph.\n\n----------------------------------------");
}

//----------------------------------------

void isComplete(int graph[100][100], int size){
	int i = 0, j = 0;

	printf("\n\n\n   ");
	i = 0;
	while(i<size){
		printf("%d ", i+1);
		i++;
	}
	i = 0;
	printf("\n   ");
	while(i<size+2){
		printf("_ ");
		i++;
	}
	printf("\n");
	i = 0, j = 0;
	while(i < size){
		j = 0;
		printf("%d| ", i+1);
		while(j < size){
			if(graph[i][j] == INF){
				printf("- ");
			}
			else{
				printf("%d ", graph[i][j]);
			}

			j++;
		}
		printf("\n");
		i++;
	}

	printf("\n\n");
	i = 0, j = 0;
	while(i < size){
		j = 0;
		while(j < size){
			if(graph[i][j] == INF){
				printf("The Graph Is Not a Complete Graph.\n\n----------------------------------------");
				return;
			}
			j++;
		}
		i++;
	}
	printf("The Graph Is a Complete Graph.\n\n----------------------------------------");
}

//----------------------------------------

int main()
{
	int i = 0, j = 0;

	FILE* file;

	file = fopen("Graph.txt", "r");
	if(file == NULL){
		printf("Failed to create file.");
    }
    else{
		while(!feof(file)){
			fscanf(file, "%d %d %d", &node[i], &dest[i], &weight[i]);
			i++;
		}
		fclose(file);
	}
	int size = i, choice;

	while(1){
		printf("\n\n1- Create Adjacency List\n2- Create Adjacency Matrix\n3- Connected Graph Control\n4- Complete Graph Control\n5- Exit\n\nChoose One: ");
		scanf("%d", &choice);

		if(choice == 1){
			while(j<size){
				InsertNodeList(node[j], dest[j], weight[j]);
				j++;
			}
			DisplayList(length);

		}
		else if(choice == 2){
			while(j<size){
				InsertNodeList(node[j], dest[j], weight[j]);
				j++;
			}
			InsertNodeMatrix(size);
			DisplayMatrix(length);
		}
		else if(choice == 3){
			while(j<size){
				InsertNodeList(node[j], dest[j], weight[j]);
				j++;
			}
			InsertNodeMatrix(size);
			isConnected(Path, length);
		}
		else if(choice == 4){
			while(j<size){
				InsertNodeList(node[j], dest[j], weight[j]);
				j++;
			}
			InsertNodeMatrix(size);

			isComplete(Path, length);
		}
		else if(choice == 5){
			printf("\nLogged Out!\n\n");
			break;
		}
		else{
			printf("\nTry Again!!!\n\n");
		}
	}


    return 0;
}
