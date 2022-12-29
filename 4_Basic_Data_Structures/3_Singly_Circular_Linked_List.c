/*
Problem Statement: Implementation of Singly Circular Linked List
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//declaration of node structure
struct node
{
	int data;
	struct node* next;
};

//function declarations
void InsertFirst(int,struct node**,struct node**);
void InsertLast(int,struct node**,struct node**);
void InsertAtPosition(int,int,struct node**,struct node**);
void DeleteFirst(struct node**,struct node**);
void DeleteLast(struct node**,struct node**);
void DeleteAtPosition(int,struct node**,struct node**);
int CountNodes(struct node*, struct node*);
void DisplayLinkedList(struct node*, struct node*);

//entry point function - program execution begins here
int main(void)
{
	//variable to hold node data
	int num = 0;
	//variable to hold position - delete or insert position
	int pos = 0;
	//variable to hold size of linked list
	int count = 0;
	//variable to hold address of first element of linked list
	struct node* First = NULL;
	//variable to hold address of last element of linked list
	struct node* Last = NULL;
	//variable to hold the user choice
	int choice = 1;
	
	//print the banner message
	printf("==================================================\n");
	printf("Implementation of SINGLY CIRCULAR LINKED LIST\n");
	printf("==================================================\n");
	
	while(choice != 0)
	{
		printf("Enter choice: \n");
		printf("1: Insert first node\n");
		printf("2: Insert last node\n");
		printf("3: Insert node at specified position\n");
		printf("4: Delete first node\n");
		printf("5: Delete last node\n");
		printf("6: Delete node at specified position\n");
		printf("7: Count nodes in linked list\n");
		printf("8: Display linked list\n");
		printf("0: Exit application\n");
		
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
				scanf("%d", &num);
				InsertLast(num,&First,&Last);
				break;
				
			case 3:
				printf("Enter node data: ");
				scanf("%d",&num);
				printf("Enter insert position: ");
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
				printf("Number of nodes = %d\n",count);
				break;
				
			case 8:
				DisplayLinkedList(First,Last);
				break;
				
			case 0:
				printf("Thank you for using the application!!!\n");
				break;
				
			default:
				printf("Invalid choice, try again\n");
		}
	}
	
	exit(0);
}

void InsertFirst(int num, struct node** Head, struct node** Tail)
{
	//create a new node
	struct node* newn = (struct node*)malloc(sizeof(struct node));
	//initialise the new node
	newn->data = num;
	newn->next = NULL;
	
	//if linked list is empty
	if((*Head == NULL)&&(*Tail == NULL))
	{
		*Head = newn;
		*Tail = newn;
	}
	//if linked list is not empty
	else
	{
		newn->next = *Head;
		*Head = newn;
	}
	
	//connect the last node to first node
	(*Tail)->next = *Head;
}

void InsertLast(int num, struct node** Head, struct node** Tail)
{
	//create new node
	struct node* newn = (struct node*)malloc(sizeof(struct node));
	//iniialise the new node
	newn->data = num;
	newn->next = NULL;
	
	//if linked list is empty
	if((*Head == NULL)&&(*Tail == NULL))
	{
		*Head = newn;
		*Tail = newn;
	}
	//if linked list is not empty
	//traverse till the last node
	else
	{
		//insert the new node after Tail
		(*Tail)->next = newn;
		*Tail = newn;
	}
	//connect the last node to the first node
	(*Tail)->next = *Head;
}

void InsertAtPosition(int num, int pos, struct node** Head, struct node** Tail)
{
	//get the size of the linked list
	int size = CountNodes(*Head,*Tail);
	//check for invalid node position
	if((pos<=0)||(pos>size+1))
	{
		printf("Invalid insert position\n");
		return;
	}
	//position is 1
	else if(pos == 1)
	{
		InsertFirst(num,Head,Tail);
	}
	//last position
	else if(pos == size+1)
	{
		InsertLast(num,Head,Tail);
	}
	//any other position
	else
	{
		//temp pointer for navigation
		struct node* temp = *Head;
		//counter variable 
		int i = 0;
		
		//navigate till one node before the insert position
		for(i=0;i<pos-1;i++)
		{
			temp = temp->next;
		}
		
		//create a new node
		struct node* newn = (struct node*)malloc(sizeof(struct node));
		//initialise the new node
		newn->data = num;
		newn->next = NULL;
		
		//insert the new node after temp
		newn->next = temp->next;
		temp->next = newn;
	}	
}

void DeleteFirst(struct node** Head, struct node** Tail)
{
	//check if linked list is empty - nothing to do, return
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
		//store the node to be deleted
		struct node* delete_node = *Head;
		*Head = (*Head)->next;
		(*Tail)->next = *Head;
	}
}

void DeleteLast(struct node** Head, struct node** Tail)
{
	//if linked list is empty
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
	//linked list has more than one nodes - navigate till the second last node
	else
	{
		//pointer to navigate
		struct node* temp = *Head;
		while(temp->next->next != *Head)
		{
			temp = temp->next;
		}
		
		struct node* delete_node = temp->next;
		*Tail = temp;
		
		//connect the last node to first node
		(*Tail)->next = *Head;
		
		free(delete_node);
	}
}

void DeleteAtPosition(int pos, struct node** Head, struct node** Tail)
{
	//get the size of the linked list
	int size = CountNodes(*Head, *Tail);
	
	//check for invalid position value
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
	//any other position - navigate till one node before the delete position
	else
	{
		//temp pointer for navigation
		struct node* temp = *Head;
		//counter variable
		int i = 0;
		
		for(i=1;i<pos-1;i++)
		{
			temp = temp->next;
		}
		
		//delete the node after temp
		struct node* delete_node = temp->next;
		
		temp->next = temp->next->next;
		free(delete_node);
	}	
}

int CountNodes(struct node* Head, struct node* Tail)
{
	int count = 0;
	
	if(Head == NULL)
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

void DisplayLinkedList(struct node* Head, struct node* Tail)
{
	if(Head == NULL)
	{
		return;
	}
	
	do
	{
		printf("| %d | -> ",Head->data);
		Head = Head->next;
	}
	while(Head != Tail->next);
	printf("\n");
}