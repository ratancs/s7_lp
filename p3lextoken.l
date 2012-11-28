%{	#include<stdio.h>
	char output[500];
%}

number	[0-9]+
keyword	"int"|"float"|"while"|"if"|"else"|"for"
operator "+"|"-"|"*"|"/"|"++"|"--"|"%"|"="
identifier [a-zA-z][a-zA-Z0-9]*

%%

{number}	{sprintf(output,"%snumber ",output);}
{keyword}	{sprintf(output,"%skeyword ",output);}
{operator}	{sprintf(output,"%soperator ",output);}
{identifier}	{sprintf(output,"%sidentifier ",output);}
[\t\n{}();:,]+	{sprintf(output,"%s%s ",output,yytext);}

%%

int main()
{
	char inp[20];

printf("\nenter file name : ");
gets(inp);
yyin=fopen(inp,"r");
yylex();
printf("\n%s",output);

}

int yywrap()
{
	return 1;
}
