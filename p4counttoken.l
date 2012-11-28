%{	#include<stdio.h>
	int nid=0,naop=0,nrop=0,nkey=0,nint=0,stmt=0;
%}

integer	[0-9]+
keyword	"int"|"float"|"while"|"if"|"else"|"for"
operator "+"|"-"|"*"|"/"|"++"|"--"|"%"
relop	">"|"!"|"<"|"<="|">="|"=="|"="
identifier [a-zA-z][a-zA-Z0-9]*
statement	";"|"\n"


%%

{integer}	{nint++;}
{keyword}	{nkey++;}
{operator}	{naop++;}
{relop}		{nrop++;}
{identifier}	{nid++;}
{statement}	{stmt++;}
.	


%%

int main()
{
	char inp[20];

printf("\nenter file name : ");
gets(inp);
yyin=fopen(inp,"r");
yylex();
printf("\ntotal \ninteger=%d\nKeyword=%d\nOperator=%d\nRelation Operator=%d\nIdentifier=%d\nStatement=%d",nint,nkey,naop,nrop,nid,stmt);

}

int yywrap()
{
	return 1;
}
