/*
Problem Statement: Implementation of Stack data structure using double circular linked list
*/

//header files for input output functions - printf(), scanf()
#include<stdio.h>
//header file for exit(), malloc(), free(), functions
#include<stdlib.h>

//declaration of node structure
struct node
{
	int data;
	struct node* next;
	struct node* prev;
};

//function declarations - functions that will help us to use and manipulate the stack data structure
void Push(int, struct node**, struct node**);
void Pop(struct node**, struct node**);
int CountNodes(struct node*, struct node*);
void DisplayStack(struct node*, struct node*);

//entry point function - program execution begins here
int main(void)
{
	//variable to hold the node data
	int num = 0;
	//variable to hold the address of first node of the stack
	struct node* First = NULL;
	//variable to hod the address of last node of the stack
	struct node* Last = NULL;
	//variable to hold the node count - size of the stack
	int count = 0;
	//variable to hold the user choice
	int choice = 1;
	
	//print the banner message
	printf("=================================================\n");
	printf("IMPLEMENTATION OF STACK DATA STRUCTURE\n");
	printf("=================================================\n");
	
	while(choice != 0)
	{
		printf("Enter choice: \n");
		printf("1: Push node\n");
		printf("2: Pop node\n");
		printf("3: Peep the node\n");
		printf("4: Count nodes\n");
		printf("5: Display the stack\n");
		printf("0: Exit the application\n");
		
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter node data: ");
				scanf("%d",&num);
				Push(num,&First,&Last);
				break;
				
			case 2:
				Pop(&First,&Last);
				break;
				
			case 3:
				num = Peep(First,Last);
				printf("Peeped node data is: %d\n",num);
				break;
				
			case 4:
				count = CountNodes(First,Last);
				printf("Number of nodes in stack are: %d\n",count);
				break;
				
			case 5:
				DisplayStack(First,Last);
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
//Push - to insert the node at the topof the stack
void Push(int num, struct node** Head, struct node** Tail)
{
	//create a new node to be pushed
	struct node* newn = (struct node*)malloc(sizeof(struct node));
	//initialise the new node
	newn->data = num;
	newn->next = NULL;
	newn->prev = NULL;
	
	//if stack is empty
	if((*Head == NULL)&&(*Tail == NULL))
	{
		*Head = newn;
		*Tail = newn;
	}
	//if the stack is not empty
	else
	{
		newn->next = *Head;
		(*Head)->prev = newn;
		
		*Head = newn;
		
		//adjust the links/connections of the first and the last nodes
		(*Head)->prev = *Tail;
		(*Tail)->next = *Head;
	}
}

//Push - function to remove the top node from the stack
void Pop(struct node** Head, struct node** Tail)
{
	//check if the stack is empty - in that case do nothing - just return
	if((*Head == NULL)||(*Tail == NULL))
	{
		return;
	}
	//if stack has one node
	else if (*Head == *Tail)
	{
		free(*Head);
		
		*Head = NULL;
		*Tail = NULL;
	}
	//if stack has more than one nodes
	else
	{
		struct node* delete_node = *Head;
		
		*Head = (*Head)->next;
		
		//adjust the links to the first and the last nodes of the stack
		(*Head)->prev = *Tail;
		(*Tail)->next = *Head;
		
		//free the node
		free(delete_node);
	}
}

//Peep - function to return the top node of the stack without deleting it
int Peep(struct node* Head, struct node* Tail)
{
	return Head->data;	
}

//CountNodes - function to return the size of the stack - number of nodes in the stack
int CountNodes(struct node* Head, struct node* Tail)
{
	int count = 0;
	//check if the stack is empty
	if((Head == NULL)&&(Tail == NULL))
	{
		return count;
	}
	//if stack is not empty
	do
	{
		count++;
		Head = Head->next;
	}
	while(Head != Tail->next);
	
	return count;
}

//Display the stack
void DisplayStack(struct node* Head, struct node* Tail)
{
	//check if stack is empty
	if((Head == NULL)&&(Tail == NULL))
	{
		printf("Stack is empty\n");
		return;
	}
	//if stack is not empty
	do
	{
		printf(" %d ",Head->data);
		Head = Head->next;
	}
	while(Head != Tail->next);
	
	printf("\n");
}