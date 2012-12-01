#include<stdio.h>
#include<string.h>
void E();
void T();
void EPRIME();
void F();
void TPRIME();
void error();
int i=0;
char str[100];

void main()
{

	printf("\nEnter the expression :");
	gets(str);
	E();

	if(i==strlen(str))
		printf("\nSUCESS");
	else
		printf("\nERROR");


}


void E()
{
	T();
	EPRIME();
}

void T()
{	
	F();
	TPRIME();
}


void EPRIME()
{
	if(str[i]=='+')
{	i++;
	T();
	EPRIME();
}
}

void TPRIME()
{	if(str[i]=='*')
{	i++;
	F();
	TPRIME();
}
}

void F()
{
	if(str[i]>='0'&&str[i]<='9'){
		i++;
		while(str[i]>='0'&&str[i]<='9')
			i++;
		}
	else
{

	if(str[i]=='('){
		i++;
		E();
		if(str[i]==')')
			i++;
		else
			error();
	}
	else
		error();
}
}

void error()
{
	printf("\nInvalid Expression");
	exit(1);
}

