/*
Problem Statement: Implementation of Singly Linear Linked List data structure using C programming language
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

/*declaration of node structure, contains two elements:
data
pointer to next node
*/
struct node
{
	int data;
	struct node* next;
};

//declaration of functions that will manipulate the linked list
//function to insert an element at the first node position of the linked list
void InsertFirst(int, struct node**);
//function to insert an element at the last node position of the linked list
void InsertLast(int, struct node**);
//function to insert node in between the linked list
void InsertAtPosition(int,int,struct node**);
//function to delete first node
void DeleteFirst(struct node**);
//function to delete last node
void DeleteLast(struct node**);
//function to delete a node from in between the linked list
void DeleteAtPosition(int,struct node**);
//function to count the number of nodes in the linked list
int CountNodes(struct node*);
//function to display the linked list
void DisplayLinkedList(struct node*);

//entry point function - program execution begins from here
int main(void)
{
	//variable to hold node data
	int num = 0;
	//variable to hold node position
	int pos = 0;
	//variable to store size of the linked list
	int count = 0;
	//variable to store the address of first node of the linked list
	struct node* Head = NULL;
	//variable to hold the user's choice, initialise to 1 so that we enter the while loop in first run itself
	int choice = 1;
	
	//print a banner message
	printf("================================================\n");
	printf("Implementation of SINGLY LINEAR LINKED LIST\n");
	printf("================================================\n");
	
	while(choice != 0)
	{
		printf("Enter your choice: \n");
		printf("1: Insert first node\n");
		printf("2: Insert last node\n");
		printf("3: Insert node at position\n");
		printf("4: Delete first node\n");
		printf("5: Delete last node\n");
		printf("6: Delete node at position\n");
		printf("7: Count nodes\n");
		printf("8: Display linked list\n");
		printf("0: Exit application\n");
		
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter node data: ");
				scanf("%d",&num);
				InsertFirst(num,&Head);
				break;
				
			case 2:
				printf("Enter node data: ");
				scanf("%d",&num);
				InsertLast(num,&Head);
				break;
				
			case 3:
				printf("Enter node data: ");
				scanf("%d",&num);
				printf("Enter insert position: ");
				scanf("%d",&pos);
				InsertAtPosition(num,pos,&Head);
				break;
				
			case 4:
				DeleteFirst(&Head);
				break;
				
			case 5:
				DeleteLast(&Head);
				break;
				
			case 6:
				printf("Enter delete position: ");
				scanf("%d",&pos);
				DeleteAtPosition(pos,&Head);
				break;
				
			case 7:
				count = CountNodes(Head);
				printf("Number of nodes = %d\n",count);
				break;
				
			case 8:
				DisplayLinkedList(Head);
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

//InsertFirst() function definition
void InsertFirst(int num, struct node** Head)
{
	//dynamically allocate memory for a node
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	//intialise the new node
	new_node->data = num;
	new_node->next = NULL;
	
	//check if linked list is empty - just point Head to the new node
	if(*Head == NULL)
	{
		*Head = new_node;
	}
	//if linked list is not empty - insert the new node at first position
	else
	{
		new_node->next = *Head;
		*Head = new_node;
	}
}

//InserLast() function definition
void InsertLast(int num, struct node** Head)
{
	//dynamically allocate memory for new node
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	//initialise the new node
	new_node->data = num;
	new_node->next = NULL;
	
	//check if linked list is empty
	if(*Head == NULL)
	{
		*Head = new_node;
	}
	//if linked list is not empty - traverse till the last node of the linked list
	else
	{
		//need temp pointer for traversing
		struct node* temp = *Head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		
		//now temp is pointing to the last node - insert the new node after temp
		temp->next = new_node;		
	}
}

//InsertAtPosition() function definition
void InsertAtPosition(int num, int pos, struct node** Head)
{
	//fetch the size of the linked list
	int size = CountNodes(*Head);
	
	//check for invalid values for pos variable
	if((pos<=0)||(pos>size+1))
	{
		printf("Invalid position\n");
		return;
	}
	//if pos is 1 - call the InsertFirst() function 
	else if(pos == 1)
	{
		InsertFirst(num,Head);
	}
	//if position is last
	else if(pos == (size+1))
	{
		InsertLast(num,Head);
	}
	//if position is some other values
	else
	{
		//temp variable for navigation
		struct node* temp = *Head;
		//counter variable
		int i = 0;
		
		//traverse till one node before the insert position
		for(i=1;i<(pos-1);i++)
		{
			temp=temp->next;
		}
		
		//now temp is pointing to the required node - after which we want to insert the node
		//create a new node
		struct node* new_node = (struct node*)malloc(sizeof(struct node));
		//initialise the new node
		new_node->data = num;
		new_node->next = NULL;
		
		//insert the new node after temp
		new_node->next = temp->next;
		temp->next = new_node;
	}	
}

//DeleteFirst() function definition
void DeleteFirst(struct node** Head)
{
	//check if linked list is empty - if so, return - do nothing
	if(*Head == NULL)
	{
		return;
	}
	//check if linked list has one node only
	else if((*Head)->next == NULL)
	{
		//temp store the node to be deleted
		struct node* delete_node = *Head;
		//point *Head to NULL - as only one node was there and it will be deleted
		*Head = NULL;
		//delete the node of LL stored in delete_node
		free(delete_node);
	}
	//linked list has more than one nodes
	else
	{
		//temp store the node to be deleted
		struct node* delete_node = *Head;
		//adjust the head pointer
		*Head = (*Head)->next;
		//free the node
		free(delete_node);
	}
}

//DeleteLast() function definition
void DeleteLast(struct node** Head)
{
	//check if linked list is empty - if so do nothing, return
	if(*Head == NULL)
	{
		return;
	}
	//if linked list has one node - delete the node that head is pointing to
	else if((*Head)->next == NULL)
	{
		struct node* delete_node = *Head;
		*Head = NULL;
		free(delete_node);
	}
	//if linked list has more than one nodes - travserse till second last node
	else
	{
		//temp pointer for navigation
		struct node* temp = *Head;
		
		//navigate till second last node
		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}
		
		//now temp is pointing to second last node - delete the node after temp
		free(temp->next);
		temp->next = NULL;
	}
}

//DeleteAtPosition() function definition
void DeleteAtPosition(int pos, struct node** Head)
{
	//get the size of the linked list
	int size = CountNodes(*Head);
	
	//check for invalid position values
	if((pos<=0)||(pos>size))
	{
		printf("Invalid delete position\n");
		return;
	}
	//if position is 1
	else if(pos == 1)
	{
		DeleteFirst(Head);
	}
	//if position is last position
	else if(pos == size)
	{
		DeleteLast(Head);
	}
	//any other position
	else
	{
		//temp pointer for navigation
		struct node* temp = *Head;
		//counter variable
		int i = 0;
		
		//navigate till one node before delete position
		for(i=1;i<(pos-1);i++)
		{
			temp = temp->next;
		}
		
		//now temp is pointing to correct position - delete the node after temp
		struct node* delete_node = temp->next;
		temp->next = temp->next->next;
		free(delete_node);
	}
	
}

//CountNodes() function definition
int CountNodes(struct node* Head)
{
	int count = 0;
	
	//traverse the linked list till Head is not equal to NULL
	while(Head != NULL)
	{
		count++;
		Head = Head->next;
	}
	
	return count;
}

//DisplayLinkedList() function definition
void DisplayLinkedList(struct node* Head)
{
	//traverse the linked list using Head pointer and display each node
	while(Head != NULL)
	{
		printf("| %d | -> ",Head->data);
		Head = Head->next;
	}
	printf("NULL\n");
}

