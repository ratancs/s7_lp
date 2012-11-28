%{	#include<stdio.h>
	int count=0;
%}


rule	[0-1]*"000"[0-1]*
err	[a-zA-Z]+	

%%

{rule}	{	count++;}
.	

%%

int main()
{
	char inp[20];
	printf("Enter file name : ");
	gets(inp);
	yyin=fopen(inp,"r");
	yylex();
	printf("\n(0+1)*000(0+1)* has occured %d number of times\n",count);
}

int yywrap()
{
	return 1;
}
