//memory violation error
//stack section is allocated around 2MB storage
//OS allocates 2MB of stack storage to each thread

#include<stdio.h>
#include<stdlib.h>

test_function(int n);

int main()
{
	test_function(1);
	return 0;
}

test_function(int n)
{
	printf("n = %d\n",n);
	test_function(n+1);
}
