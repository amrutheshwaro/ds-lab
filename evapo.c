#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
char postfix[30], ch;
int num, st[30], top=-1, op2, op1, rt;
void push(int num)
{
	st[++top]=num;
}
int pop()
{
	return(st[top--]);
}
void main()
{
	int j=0;
	printf("Enter the postfix expression.\n");
	gets(postfix);
	while(postfix[j]!='\0')
	{
		ch=postfix[j];
		if(isalpha(ch))
		{
			printf("Enter the value for %c\n", ch);
			scanf("%d", &num);
			push(num);
		}
		else
		{
			op2=pop();
			op1=pop();
			switch(ch)
			{
				case '^': rt=pow(op1,op2);
					  push(rt);
					  break;					  
				case '+': rt=op1+op2;
					  push(rt);
					  break;
				case '*': rt=op1*op2;
					  push(rt);
					  break;
				case '/': rt=op1/op2;
					  push(rt);
					  break;
				case '-': rt=op1-op2;
					  push(rt);
					  break;
			}
		}
		j++;
	}
	printf("Output= %d\n", st[top]);
}
