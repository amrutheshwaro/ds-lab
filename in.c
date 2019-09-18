#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define SIZE 30
char s[SIZE], infix[SIZE], postfix[SIZE], ch, temp, x;
int top=-1, i=0, j=0;
void push(char ch)
{	
	if(top>=SIZE-1)
		printf("Stack overflow.\n");
	else
		s[++top]=ch;
}
char pop()
{
	char temp;
	if(top<0)
	{
		printf("Stack underflow: Invalid infix expression.\n");
		getchar();
		exit(0);
	}
	else
	{
		temp=s[top--];
		return(temp);
	}
}
int isoperator(char ch)
{
	if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^')
		return 1;
	else
		return 0;
}
int precedence(char ch)
{
	switch(ch)
	{
		case '^': return (4);
			  break;
		case '*':
		case '/': return (3);
			  break;
		case '+': 
		case '-': return (2);
			  break;
		default: return (1);
	}
}
void intopo()
{
	push('(');
	strcat(infix,")");
	ch=infix[i];
	while(ch!='\0')
	{
		if(ch=='(')
			push(ch);
		else if(isdigit(ch)||isalpha(ch))
		{
			postfix[j]=ch;
			j++;
		}
		else if(isoperator(ch)==1)
		{
			x=pop();
			while(isoperator(x)==1&&precedence(x)>=precedence(ch))
			{
				postfix[j]=x;
				j++;
				x=pop();
			}
			push(x);
			push(ch);
		}
		else if(ch==')')
		{
			x=pop();
			while(x!='(')
			{
				postfix[j]=x;
				j++;
				x=pop();
			}
		}
		else
		{
			printf("Invalid infix expression.\n");
			getchar();
			exit(1);
		}
		i++;
		ch=infix[i];
	}
	if(top>0)
	{
		printf("Invalid infix expression.\n");
		getchar();
		exit(1);
	}
	postfix[j]='\0';
}
int main()
{
	printf("Enter the expression.\n");
	gets(infix);
	intopo();
	printf("Postfix expression:\n");
	puts(postfix);
	return 0;
}


			
