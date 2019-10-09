#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define size 30
char s[size], infix[size], postfix[size], temp, ch;
int top=-1, j=0, i=0;
void push(char ch)
{
	s[++top]=ch;
}
char pop()
{
	return s[top--];
}
int isoperator(char ch)
{
	if(ch=='^'||ch=='/'||ch=='*'||ch=='+'||ch=='-')
		return 1;
	else
		return 0;
}
int precedence(char ch)
{
	switch(ch)
	{
		case '^': return 4;
			  break;
		case '/':
		case '*': return 3;
			  break;
		case '+':
		case '-': return 2;
			  break;
		default: return 0;
			 break;
	}
}
void main()
{
	printf("Enter the infix expression.\n");
	gets(infix);
	while(infix[i]!='\0')
	{
		ch=infix[i];
		if(isalpha(ch))
		{
			postfix[j]=ch;
			j++;
		}
		else if(ch=='(')
			push(ch);
		else if(isoperator(ch)==1)
		{
			if(ch!='^')
				while(top!=-1&&precedence(s[top])>=precedence(ch))
				{
					postfix[j]=pop();
					j++;
				}
			push(ch);
		}
		else if(ch==')')
		{
			while(s[top]!='(')
			{
				postfix[j]=pop();
				j++;
			}
			temp=pop();
		}
		else
			printf("Invalid infix expression.\n");
		i++;
	}
	while(top>=0)
	{
		postfix[j]=pop();
		j++;
	}
	postfix[j]='\0';
	puts(postfix);
}
			

