#include<stdio.h>
#include<stdlib.h>
#define SIZE 30
int n, i, s[SIZE], top;
void Push()
{
	if(top==(SIZE-1))
		printf("Overflow\n");
	else
	{
		printf("Enter a number.\n");
		scanf("%d", &n);
		s[++top]=n;
	}	
}
void Pop()
{
	if (top==-1)
		printf("Underflow.\n");
	else
		printf("%d", s[top--]);
}
void Display()
{
	if(top==-1)
		printf("Stack is empty.\n");
	else
		for(i=0; i<=top; i++)
			printf("%d\n", s[i]);
}
void main()
{
	int ch;
	while(1)
	{
		printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
		printf("Enter your choice.\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: Push();
				break;
			case 2: Pop();
				break;
			case 3: Display();
				break;
			case 4: exit(0);
		}
		
	}
}

