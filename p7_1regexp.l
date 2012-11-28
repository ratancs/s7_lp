%{	#include<stdio.h>
	int count=0;
%}


rule	"aa"[a-b]*"bb"
err	[0-9]+	

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
	printf("\naa(a+b)*bb has occured %d number of times\n",count);
}

int yywrap()
{
	return 1;
}
