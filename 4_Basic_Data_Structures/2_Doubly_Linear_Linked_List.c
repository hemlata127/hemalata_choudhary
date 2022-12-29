/*
Problem Statement: Implementation of doubly linear linked list using C programming language
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//declaration of the node structure
struct node
{
	int data;
	struct node* next;
	struct node* prev;
};

//function declarations - functions that will manipulate and use the linked list
void InsertFirst(int,struct node**);
void InsertLast(int, struct node**);
void InsertAtPosition(int,int,struct node**);
void DeleteFirst(struct node**);
void DeleteLast(struct node**);
void DeleteAtPosition(int,struct node**);
int CountNodes(struct node*);
void DisplayNodes(struct node*);

//entry point function
int main(void)
{
	//variable for node data
	int num = 0;
	//variable for node position
	int pos = 0;
	//variable for size of the linked list
	int count = 0;
	//variable for user choice
	int choice = 1;
	//variable for storing the address of first node of the linked list
	struct node* Head = NULL;
	
	//Display a banner message
	printf("=============================================\n");
	printf("Implementation of DOUBLY LINEAR LINKED LIST\n");
	printf("=============================================\n");
	
	while(choice != 0)
	{
		printf("Enter choice: \n");
		printf("1: Insert first node\n");
		printf("2: Insert last node\n");
		printf("3: Insert node at specified poistion\n");
		printf("4: Delete first node\n");
		printf("5: Delete last node\n");
		printf("6: Delete node from specified position\n");
		printf("7: Count nodes in the linked list\n");
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
				printf("Number of nodes: %d\n",count);
				break;
				
			case 8:
				DisplayNodes(Head);
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
//function to insert first node
void InsertFirst(int num, struct node** Head)
{
	//dynamically allocate memory for one new node
	struct node* newn = (struct node*)malloc(sizeof(struct node));
	//initialise the new node
	newn->data = num;
	newn->next = NULL;
	newn->prev = NULL;
	
	//check if linked list is empty
	if(*Head == NULL)
	{
		*Head = newn;
	}
	//if linked list is not empty - insert the new node
	else
	{
		newn->next = *Head;
		(*Head)->prev = newn;
		*Head = newn;
	}	
}

//function definition - to insert last node
void InsertLast(int num, struct node** Head)
{
	//dynamically allocate memory for a new node
	struct node* newn = (struct node*)malloc(sizeof(struct node));
	
	//initialise the new node
	newn->data = num;
	newn->next = NULL;
	newn->prev = NULL;
	
	//check if linked list is empty
	if(*Head == NULL)
	{
		*Head = newn;
	}
	//if linked list is not empty - traverse till the last node
	else
	{
		//temp pointer to traverse the linked list
		struct node* temp = *Head;
		//traverse till last node
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		
		//now temp is pointing to last node - insert node after temp
		newn->prev = temp;
		temp->next = newn;
	}
}

//function definition to insert a node at the specified poistion
void InsertAtPosition(int num, int pos, struct node** Head)
{
	//get the size of the linked list
	int size = CountNodes(*Head);
	
	//check for invalid position values
	if((pos<=0)||(pos>size+1))
	{
		printf("Invalid insert position\n");
		return;
	}
	//if position is 1
	else if(pos == 1)
	{
		InsertFirst(num,Head);
	}
	//if position is last
	else if(pos == (size+1))
	{
		InsertLast(num,Head);
	}
	//other position
	else
	{
		//temp pointer to navigate to the required position - one node before insert position
		struct node* temp = *Head;
		//counter variable
		int i = 0;
		
		//navigate till required position
		for(i=1;i<(pos-1);i++)
		{
			temp = temp->next;
		}
		
		//dynamically allocate memory for a new node
		struct node* newn = (struct node*)malloc(sizeof(struct node));
		//initialise the new node
		newn->data = num;
		newn->next = NULL;
		newn->prev = NULL;
		
		//insert this new node after temp
		newn->next = temp->next;
		newn->prev = newn;
		temp->next->prev = newn;
		temp->next = newn;
	}
}

//function definition for deleting the first node
void DeleteFirst(struct node** Head)
{
	//check if linked list ie empty
	if(*Head == NULL)
	{
		return;
	}
	//if linked list has one node
	else if((*Head)->next == NULL)
	{
		free(*Head);
		*Head = NULL;
	}
	//if linked list has more than one nodes
	else
	{
		//temp store the node to be deleted
		struct node* delete_node = *Head;
		*Head = (*Head)->next;
		(*Head)->prev = NULL;
		
		free(delete_node);
	}
}

//function definition to delete the last node
void DeleteLast(struct node** Head)
{
	//if linked list has no node
	if(*Head == NULL)
	{
		return;
	}
	//if linked list has one node
	else if((*Head)->next == NULL)
	{
		free((*Head)->next);
		*Head = NULL;
	}
	//if linked list has more than one nodes - navigate till second last node
	else
	{
		//temp pointer to traverse the linked list
		struct node* temp = *Head;
		
		//traverse till second last node
		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}
		
		free(temp->next);
		temp->next = NULL;
	}
}

//function definition to delete node at specified position
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
	//if pos is 1
	else if (pos == 1)
	{
		DeleteFirst(Head);
	}
	//if pos is last
	else if(pos == size)
	{
		DeleteLast(Head);
	}
	//any other position
	else
	{
		//temp pointer to navigate till one node before delete position
		struct node* temp = *Head;
		//counter variable
		int i = 0;
		
		//navigate till the required position
		for(i=1;i<(pos-1);i++)
		{
			temp = temp->next;
		}
		
		//delete the node after temp
		struct node* delete_node = temp->next;
		temp->next = temp->next->next;
		temp->next->prev = temp;
		
		free(delete_node);	
	}	
}

//function definition for counting the nodes
int CountNodes(struct node* Head)
{
	int count = 0;
	
	while(Head != NULL)
	{
		count++;
		Head = Head->next;
	}
	
	return count;
}

//function definition for displaying the linked list
void DisplayNodes(struct node* Head)
{
	while(Head != NULL)
	{
		printf("| %d | <-> ",Head->data);
		Head = Head->next;
	}
	
	printf("NULL\n");
}