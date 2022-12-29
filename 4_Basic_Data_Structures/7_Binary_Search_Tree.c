/*
Problem Statement: Implementation of binary search tree data structure using C programming language
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//macro definition
#define TRUE 1
#define FALSE 0

//typedef
typedef int BOOL;


//declaration of node structure
struct node
{
	int data;
	struct node* rchild;
	struct node* lchild;
};

//function declaration
void InsertNode(int,struct node**);
BOOL SearchNode(int,struct node*);
void PreOrder(struct node*);
void PostOrder(struct node*);
void InOrder(struct node*);

//entry point function
int main(void)
{
	//variable to hold the address of root node
	struct node* First = NULL;
	//variable to hold node data
	int num = 0;
	//variable to hold choice
	int choice = 1;
	//variable to hold search result
	BOOL result = FALSE;
	
	//print the banner message
	printf("===================================================\n");
	printf("IMPLEMENTATION OF BINARY SAERCH TREE\n");
	printf("===================================================\n");
	
	while(choice != 0)
	{
		printf("Enter choice: \n");
		printf("1: Insert node\n");
		printf("2: Search node\n");
		printf("3: Pre order display\n");
		printf("4: Post order display\n");
		printf("5: In order display\n");
		printf("0: Exit application\n");
		
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter the node data: ");
				scanf("%d",&num);
				InsertNode(num,&First);
				break;
				
			case 2:
				printf("Enter node to search: ");
				scanf("%d",&num);
				result = SearchNode(num,First);
				if(result == TRUE)
				{
					printf("%d is present\n",num);
				}
				else if(result == FALSE)
				{
					printf("%d is not present\n",num);
				}
				break;
				
			case 3:
				PreOrder(First);
				printf("\n");
				break;
				
			case 4:
				PostOrder(First);
				printf("\n");
				break;
				
			case 5:
				InOrder(First);
				printf("\n");
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

//function definition
void InsertNode(int num, struct node** Root)
{
	//create a new node
	struct node* newn = (struct node*)malloc(sizeof(struct node));
	//initialise the new node
	newn->data = num;
	newn->rchild = NULL;
	newn->lchild = NULL;
	
	if(*Root == NULL)
	{
		*Root = newn;
	}
	else
	{
		//create a temp variable for navigation through the binary tree
		struct node* temp = *Root;
		//infinite loop
		while(1)
		{
			//equal value of num
			if(temp->data == num)
			{
				printf("Element is already present\n");
				break;
			}
			//lower value of num
			else if(num < temp->data)
			{
				if(temp->lchild == NULL)
				{
					temp->lchild = newn;
					break;
				}
				temp = temp->lchild;
			}
			//higher value of num
			else if(num > temp->data)
			{
				if(temp->rchild == NULL)
				{
					temp->rchild = newn;
					break;
				}
				temp = temp->rchild;
			}
		}
	}
}

//function to search the node in binary search tree
BOOL SearchNode(int num, struct node* Root)
{
	while(Root != NULL)
	{
		if(Root->data == num)
		{
			break;
		}
		else if(num<Root->data)
		{
			Root = Root->lchild;
		}
		else if(num>Root->data)
		{
			Root = Root->rchild;
		}
	}
	//chck value of Root after the entire traversal
	if (Root == NULL)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

//In order display
void InOrder(struct node* Root)
{
	if(Root != NULL)
	{
		InOrder(Root->lchild);
		printf("%d ",Root->data);
		InOrder(Root->rchild);
	}
}

//Pre order display
void PreOrder(struct node* Root)
{
	if(Root != NULL)
	{
		printf("%d ",Root->data);
		PreOrder(Root->lchild);
		PreOrder(Root->rchild);
	}
}

//Post Order display
void PostOrder(struct node* Root)
{
	if(Root != NULL)
	{
		PostOrder(Root->lchild);
		PostOrder(Root->rchild);
		printf("%d ",Root->data);
	}
}