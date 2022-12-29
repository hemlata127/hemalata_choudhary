/*
Write a program to define customer record application that stores the information about customer account and performs search for a particular customer account number.
*/

#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define SIZE 3

typedef int BOOL;

//declaration of structure to store customer information
struct record
{
	char* name;
	int account_number;
	char account_type;
	float balance;	
};

//function declaration - search function
struct record Search(struct record[],int,BOOL*);

int main(void)
{
	//initialise the customer records - array of 3 records
	struct record customer[SIZE] = {{"Anwesha",3333,'C',33.33},{"Utkarsh",6666,'O',66.66},{"Hemalata",9999,'D',99.99}};
	
	int search_account_number = 0;
	struct record search_customer_record;
	BOOL flag = FALSE;
	
	printf("Enter account number to search, enter 0 to end search: ");
	scanf("%d",&search_account_number);
	
	while(search_account_number != 0)
	{	
		search_customer_record = Search(customer,search_account_number,&flag);
		
		if(flag == TRUE)
		{
			printf("Customer record found\n");
			printf("Customer name = %s\n",search_customer_record.name);
			printf("Account number = %d\n",search_customer_record.account_number);
			printf("Acocunt type = %c\n",search_customer_record.account_type);
			printf("Balance = %f\n",search_customer_record.balance);
		}	
		else if(flag == FALSE)
		{
			printf("Record not found\n");
		}
		
		printf("Enter account number to search, enter 0 to end search: ");
		scanf("%d",&search_account_number);
	}	
	
	exit(0);
}

struct record Search(struct record table[],int search_account_number, BOOL* flag)
{
	int i = 0;
	struct record search_record = {"\0",0,'O',0.0};
	
	for(i=0;i<SIZE;i++)
	{
		*flag = FALSE;
		if(table[i].account_number == search_account_number)
		{
			*flag = TRUE;
			search_record = table[i];
			break;
		}
	}
	return search_record;
}
