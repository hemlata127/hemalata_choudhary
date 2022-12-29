/*
Problem Statement: Implementation of Queue data structure using double circular linked list
*/

//header file inclusion
//header file for input output functions
#include<stdio.h>
//hedaer file for exit, malloc, free functions
#include<stdlib.h>

//declaration of the node structure
struct node
{
	int data;
	struct node* next;
	struct node* prev;
};

//function declaration - functions using which we can use and manipulate the tree data structure
void EnQueue(int, struct node**, struct node**);
void DeQueue(struct node**, struct node**);
int CountNodes(struct node*, struct node*);
void DisplayQueue(struct node*, struct node*);

//entry point function - program execution begins here
int main(void)
{
	//variable to hold the node data
	int num = 0;
	//variable to hold the address of the first node of the Queue
	struct node* First = NULL;
	//variable to hold the address of the last node of the Queue
	struct node* Last = NULL;
	//variable to hold the size of the Queue - number of nodes in the Queue
	int count = 0;
	//variable to hold the user choice
	int choice = 1;
	
	//print the banner message
	printf("=========================================================================\n");
	printf("IMPLEMENTATION OF QUEUE DATA STRUCTURE USING DOUBLY CIRCULAR LINKED LIST\n");
	printf("=========================================================================\n");
	
	while(choice != 0)
	{
		printf("Enter your choice: \n");
		printf("1: EnQueue (Insert node in Queue)\n");
		printf("2: DeQueue (Delete Node from Queue)\n");
		printf("3: Count nodes\n");
		printf("4: Display Queue\n");
		printf("0: Exit the application\n");
		
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter node data: ");
				scanf("%d",&num);
				EnQueue(num,&First,&Last);
				break;
				
			case 2:
				DeQueue(&First,&Last);
				break;
				
			case 3:
				count = CountNodes(First,Last);
				printf("Number of nodes: %d\n",count);
				break;
				
			case 4:
				DisplayQueue(First,Last);
				break;
				
			case 0:
				printf("Thank you for using the application!!!\n");
				break;
				
			default:
				printf("Invalid choice\n");
		}
	}
	
	exit(0);
}

//function definitions
//function to insert node into the Queue
void EnQueue(int num, struct node** Head, struct node** Tail)
{
	//create a new node
	struct node* newn = (struct node*)malloc(sizeof(struct node));
	//initialise the new node
	newn->data = num;
	newn->next = NULL;
	newn->prev = NULL;
	
	//check if Queue is empty
	if((*Head == NULL)&&(*Tail == NULL))
	{
		*Head = newn;
		*Tail = newn;
	}
	//if Queue is not empty
	else
	{
		newn->next = *Head;
		(*Head)->prev = newn;
		
		*Head = newn;
		
		//readjust the pointers that connect the first and the last nodes
		(*Head)->prev = *Tail;
		(*Tail)->next = *Head;
	}	
}

//function to remove a node from the Queue
void DeQueue(struct node** Head, struct node** Tail)
{
	//check if Queue is empty
	if((*Head == NULL)&&(*Tail == NULL))
	{
		printf("Queue is empty\n");
		return;
	}
	//if Queue has one node
	else if(*Head == *Tail)
	{
		free(*Head);
		
		*Head = NULL;
		*Tail = NULL;
	}
	//if Queue has more than one nodes
	else
	{
		//temporarily store the node to be deleted
		struct node* delete_node = *Tail;
		
		*Tail= (*Tail)->prev;
		
		//readjust the pointers that connect the first and last nodes of the Queue
		(*Head)->prev = *Tail;
		(*Tail)->next = *Head;
		
		//delete the node
		free(delete_node);		
	}
}

//function to find the size of the Queue
int CountNodes(struct node* Head, struct node* Tail)
{
	int count = 0;
	
	//check if the Queue is empty
	if((Head == NULL)&&(Tail == NULL))
	{
		return count;
	}
	
	do
	{
		count++;
		Head = Head->next;
	}
	while(Head != Tail->next);
	
	return count;
}

//function to display the nodes of the Queue
void DisplayQueue(struct node* Head, struct node* Tail)
{
	//check if the Queue is empty
	if((Head == NULL)&&(Tail == NULL))
	{
		printf("Queue is empty\n");
		return;
	}
	
	do
	{
		printf(" %d ",Head->data);
		Head = Head->next;
	}
	while(Head != Tail->next);
	
	printf("\n");
}