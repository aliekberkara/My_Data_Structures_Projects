#include <stdio.h>
#include <stdlib.h>
#define SIZE 20


struct Node
{
    char data;
    struct Node* LeftNode;
    struct Node* RightNode;

};
struct Node* RootNode = NULL;

struct Node* Queue[SIZE];
int front = -1, rear = -1;

void EnQueue(struct Node* node)
{
    if(rear == SIZE - 1)
    {
        printf("\nQueue is Full!\n");
        return;
    }

    if(front == -1)
        front = 0;

    rear++;
    Queue[rear] = node;

}

struct Node* Dequeue()
{

    if(front == -1 || front > rear)
    {
        printf("\nQueue is Empty\n");
        return;
    }
    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    struct Node* temp = Queue[front];
    front++;
    return temp;
}


struct Node* CreateNode(char Data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = Data;
    newNode->LeftNode = NULL;
    newNode->RightNode = NULL;

    return newNode;
}

// Left - Root - Right....

void InOrder(struct Node* temp)
{
    if(temp == NULL)
        return;

    InOrder(temp->LeftNode);
    printf(" %c ", temp->data);
    InOrder(temp->RightNode);
}

void InsertNode(struct Node* first, char add)
{
    if(RootNode == NULL)
    {
        RootNode = CreateNode(add);
        return;
    }


    EnQueue(first);
    while(front != -1 && front <= rear)
    {
        struct Node* temp = Queue[front];
        Dequeue();
        if(temp->LeftNode == NULL)
        {
            temp->LeftNode = CreateNode(add);
            break;
        }
        else
        {
            EnQueue(temp->LeftNode);
        }

        if(temp->RightNode == NULL)
        {
            temp->RightNode = CreateNode(add);
            break;
        }
        else
        {
            EnQueue(temp->RightNode);
        }

    }
}


void LevelOrderTraversal(struct Node* root)
{
    front = -1;
    rear = -1;

    EnQueue(root);

    while(front != -1 && front <= rear)
    {
        struct Node* temp = Queue[front];
        Dequeue();
        printf(" %c ", temp->data);

        if(temp->LeftNode != NULL)
            EnQueue(temp->LeftNode);
        if(temp->RightNode != NULL)
            EnQueue(temp->RightNode);
    }
}


void DeleteFromLast(struct Node* first, struct Node* Deleted)
{
    front = -1;
    rear = -1;

    EnQueue(first);

    while(front != -1 && front <= rear)
    {
        struct Node* temp = Queue[front];
        Dequeue();

        if(temp == Deleted)
        {
            temp = NULL;
            free(Deleted);
            return;
        }

        if(temp->RightNode != NULL)
        {
            if(temp->RightNode == Deleted)
            {
                temp->RightNode = NULL;
                free(Deleted);
                return;
            }
            else
                EnQueue(temp->RightNode);
        }

        if(temp->LeftNode != NULL)
        {
            if(temp->LeftNode == Deleted)
            {
                temp->LeftNode = NULL;
                free(Deleted);
                return;
            }
            else
                EnQueue(temp->LeftNode);
        }
    }
}


struct Node* DeleteNode(struct Node* root, char data)
{
    front = -1;
    rear = -1;
    if(root->LeftNode == NULL && root->RightNode == NULL)
    {
        if(root->data == data)
            return NULL;
        else
            return root;
    }
    struct Node* SearchedNode = NULL;
    EnQueue(root);
    struct Node* temp = NULL;
    while(front != -1 && front <= rear)
    {
        temp = Queue[front];
        Dequeue();

        if(temp->data == data)
            SearchedNode = temp;
        if(temp->LeftNode != NULL)
            EnQueue(temp->LeftNode);
        if(temp->RightNode != NULL)
            EnQueue(temp->RightNode);


    }
    if(SearchedNode != NULL)
    {
        char temp1 = temp->data;
        DeleteFromLast(root, temp);
        SearchedNode->data = temp1;
    }

    return root;
}


int main()
{
    InsertNode(RootNode, 'A');
    InsertNode(RootNode, 'B');
    InsertNode(RootNode, 'C');
    InsertNode(RootNode, '1');
    InsertNode(RootNode, '2');
    InsertNode(RootNode, '3');
    InsertNode(RootNode, '4');


    printf("---------------------------\n");
    LevelOrderTraversal(RootNode);

    printf("\n---------------------------\n");
    RootNode = DeleteNode(RootNode, 'A');
    LevelOrderTraversal(RootNode);

	printf("\n---------------------------\n");

	RootNode = DeleteNode(RootNode, 'B');
    LevelOrderTraversal(RootNode);

	printf("\n---------------------------\n");

	RootNode = DeleteNode(RootNode, 'C');
    LevelOrderTraversal(RootNode);

	printf("\n---------------------------\n");

	return 0;
}
