/*
Problem Statement: Implementation of Doubly Circular Linked List
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//declaration of node structure
struct node
{
	int data;
	struct node* next;
	struct node* prev;
};

//function declaration
void InsertFirst(int,struct node**,struct node**);
void InsertLast(int,struct node**,struct node**);
void InsertAtPosition(int,int,struct node**,struct node**);
void DeleteFirst(struct node**,struct node**);
void DeleteLast(struct node**,struct node**);
void DeleteAtPosition(int,struct node**,struct node**);
int CountNodes(struct node*,struct node*);
void DisplayLinkedList(struct node*,struct node*);

//entry point function - function declaration begins here
int main(void)
{
	//variable to hold node data
	int num = 0;
	//variable to hold node position
	int pos = 0;
	//variable to hold size of linked list
	int count = 0;
	//variable to hold address of first element of linked list
	struct node* First = NULL;
	//variable to hold the address of last element of linked list
	struct node* Last = NULL;
	//variable to hold user choice
	int choice = 1;
	
	//print the banner message for the program
	printf("============================================\n");
	printf("Implementation of DOUBLY CIRCULAR LINKED LIST\n");
	printf("============================================\n");
	
	while(choice != 0)
	{
		printf("Enter choice: \n");
		printf("1: Insert first node\n");
		printf("2: Insert last node\n");
		printf("3: Insert node at specified position\n");
		printf("4: Delete first node\n");
		printf("5: Delete last node\n");
		printf("6: Delete node at specified position\n");
		printf("7: Display size of linked list\n");
		printf("8: Display the linked list\n");
		printf("0: Exit the application\n");
		
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter node data: ");
				scanf("%d",&num);
				InsertFirst(num,&First,&Last);
				break;
				
			case 2:
				printf("Enter node data: ");
				scanf("%d",&num);
				InsertLast(num,&First,&Last);
				break;
				
			case 3:
				printf("Enter the node data: ");
				scanf("%d",&num);
				printf("Enter the insert position: ");
				scanf("%d",&pos);
				InsertAtPosition(num,pos,&First,&Last);
				break;
				
			case 4:
				DeleteFirst(&First,&Last);
				break;
				
			case 5:
				DeleteLast(&First,&Last);
				break;
				
			case 6:
				printf("Enter delete position: ");
				scanf("%d",&pos);
				DeleteAtPosition(pos,&First,&Last);
				break;
				
			case 7:
				count = CountNodes(First,Last);
				printf("Number of nodes in linked list = %d\n",count);
				break;
				
			case 8:
				DisplayLinkedList(First,Last);
				break;
				
			case 0:
				printf("Thank you for using the application!!!\n");
				break;
				
			default:
				printf("Invalid choice, please try again\n");
		}
	}
	
	exit(0);
}

//function definitions
//function to insert first node
void InsertFirst(int num, struct node** Head, struct node** Tail)
{
	//create a new node
	struct node* newn = (struct node*)malloc(sizeof(struct node));
	//initialise the new node
	newn->data = num;
	newn->next = NULL;
	newn->prev = NULL;
	
	//check if linked list is empty
	if((*Head == NULL)&&(*Tail == NULL))
	{
		*Head = newn;
		*Tail = newn;
	}
	//if linked list is not empty
	else
	{
		newn->next = *Head;
		(*Head)->prev = newn;
		*Head = newn;
	}
	//join the last node to the first node and first node to the last node
	(*Tail)->next = *Head;
	(*Head)->prev = *Tail;
}

//function to insert node at the last
void InsertLast(int num, struct node** Head, struct node** Tail)
{
	//create a new node
	struct node* newn = (struct node*)malloc(sizeof(struct node));
	//initialise the new node
	newn->data = num;
	newn->next = NULL;
	newn->prev = NULL;
	
	//check if linked list is empty
	if((*Head == NULL)&&(*Tail == NULL))
	{
		*Head = newn;
		*Tail = newn;
	}
	//if linked list is not empty
	else
	{
		newn->prev = *Tail;
		(*Tail)->next = newn;
		*Tail = newn;
	}
	//connect the first node to the last node and the last node to the first node
	(*Head)->prev = *Tail;
	(*Tail)->next = *Head;
}

//function to insert node at specified position
void InsertAtPosition(int num, int pos, struct node** Head, struct node** Tail)
{
	//get the size of the linked list
	int size = CountNodes(*Head,*Tail);
	
	//check for invalid insert position
	if((pos<=0)||(pos>size+1))
	{
		printf("Invalid insert position");
		return;
	}
	//if position is 1
	else if(pos == 1)
	{
		InsertFirst(num,Head,Tail);
	}
	//if position is last
	else if(pos == (size+1))
	{
		InsertLast(num,Head,Tail);
	}
	//any other position
	else
	{
		//temp pointer to navigate till the required position - one node before the insert position
		struct node* temp = *Head;
		//counter variable
		int i = 0;
		
		//navigate till one node before insert position
		for(i=1;i<pos-1;i++)
		{
			temp = temp->next;
		}
		
		//create a new node
		struct node* newn = (struct node*)malloc(sizeof(struct node));
		//initialise the new node
		newn->data = num;
		newn->next = NULL;
		newn->prev = NULL;
		
		//insert new node after temp
		newn->next = temp->next;
		newn->prev = temp;
		temp->next = newn;
		temp->next->next->prev = newn;
	}	
}

//function to delete first node
void DeleteFirst(struct node** Head, struct node** Tail)
{
	//check if the linked list is empty - do nothing - return
	if((*Head == NULL)&&(*Tail == NULL))
	{
		return;
	}
	//if linked list has one node
	else if(*Head == *Tail)
	{
		free(*Head);
		*Head = NULL;
		*Tail = NULL;
	}
	//if linked list has more than one nodes
	else
	{
		//temporarily store the node to be deleted
		struct node* delete_node = *Head;
		*Head = (*Head)->next;
		
		//adjust the link between the first node and last node
		(*Head)->prev = *Tail;
		(*Tail)->next = *Head;
		
		free(delete_node);
	}	
}

//function to delete the last node
void DeleteLast(struct node** Head, struct node** Tail)
{
	//check if the linked list is empty - do nothing - return
	if((*Head == NULL)&&(*Tail == NULL))
	{
		return;
	}
	//if linked list has one node
	if(*Head == *Tail)
	{
		free(*Head);
		*Head = NULL;
		*Tail = NULL;
	}
	//if linked list has more than one nodes
	else
	{
		//temporarily store the node to be deleted
		struct node* delete_node = *Tail;
		
		*Tail = (*Tail)->prev;
		
		//adjust the link between the first and the last nodes
		(*Head)->prev = *Tail;
		(*Tail)->next = *Head;
		
		free(delete_node);
	}
}

//function to delete node at the specified position
void DeleteAtPosition(int pos, struct node** Head, struct node** Tail)
{
	//get the size of the linked list
	int size = CountNodes(*Head,*Tail);
	
	//check for invalid delete position
	if((pos<=0)||(pos>size))
	{
		printf("Invalid delete position\n");
		return;
	}
	//if position is 1
	else if(pos == 1)
	{
		DeleteFirst(Head,Tail);
	}
	//if position is last
	else if(pos == size)
	{
		DeleteLast(Head,Tail);
	}
	//any other position
	else
	{
		//temp point for traversing till the required node - one node before the delete position
		struct node* temp = *Head;
		//counter variable
		int i = 0;
		
		//navigate till one node before the delete position
		for(i=1;i<pos-1;i++)
		{
			temp = temp->next;
		}
		
		//delete the node after the temp node
		struct node* delete_node = temp->next;
		
		temp->next = temp->next->next;
		temp->next->prev = temp;
		
		free(delete_node);
	}
	
}

//function to count the nodes
int CountNodes(struct node* Head, struct node* Tail)
{
	int count = 0;
	
	//check is the linked list is empty
	if((Head == NULL)&&(Tail == NULL))
	{
		return count;
	}
	//if linked list is not empty
	do
	{
		count++;
		Head = Head->next;
	}
	while(Head != Tail->next);
	
	return count;
}

//function to display the linked list
void DisplayLinkedList(struct node* Head, struct node* Tail)
{
	//check if the linked list is empty
	if((Head == NULL)&&(Tail == NULL))
	{
		return;
	}
	//if linked list is not empty
	do
	{
		printf("| %d | <-> ",Head->data);
		Head = Head->next;
	}
	while(Head != Tail->next);
	
	printf("\n");
}