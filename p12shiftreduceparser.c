#include<stdio.h>
#include<string.h>
void push(char);
char pop();
char peek();
void error();
char inp[100];
char stack[100];
int stkptr=-1;

void main()
{	
	int i=0;
	char c;
	printf("\nEnter the Expression");
	gets(inp);
	push('$');

	while(i<strlen(inp))
	{

		if(inp[i]>='0'&&inp[i]<='9')
		{
			while(inp[i]>='0'&&inp[i]<='9')i++;
			push('E');
		}

		else if(inp[i]=='+'||inp[i]=='-'||inp[i]=='*'||inp[i]=='/')
				{push(inp[i]);i++;}
		else
			error();
		
	
	}


while(stkptr>=3)
{
	
if(stack[stkptr]=='E'&&(stack[stkptr-1]=='+'||stack[stkptr-1]=='-'||stack[stkptr-1]=='*'||stack[stkptr-1]=='/')&&stack[stkptr-2]=='E')
			{		pop();	pop();
			}

}
	
if(stack[stkptr]=='E'&&stack[stkptr-1]=='$')
	printf("SUCESS");
else
	error();
	
}	

void push(char a)
{	stack[++stkptr]=a;}
char pop()
{	return stack[stkptr--];}
char peek()
{	return	stack[stkptr];}
void error()
{	printf("\nERROR");exit(0);}		
