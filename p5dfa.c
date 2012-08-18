//program to check given regular expression is of form (a/b)*abc
// after solving the NFA to DFA ,the simple input to output table generated is
//	current-state	input-symbol	output-state
//		1		a		2
//		1		b		1
//		2		a		2		
//		2		b		3			
//		3		a		2	
//		3		b		4
//		4		-		sucess
// Implimenting via if-else
#include<stdio.h>
#include<string.h>
void main()
{
	int state=1,len,i=0;
	char str[50];
	printf("\n Enter the Expression : ");
	gets(str);
	len=strlen(str);

	while(i<len)
	{
		if(state==1 && str[i]=='a')
{			printf("\n in-state= %d  in-symbol= %c  out-state= %d",state,str[i],2);state=2;}
		if(state==1 && str[i]=='b')
{			printf("\n in-state= %d  in-symbol= %c  out-state= %d",state,str[i],1);state=1;}

		if(state==2 && str[i]=='a')
{			printf("\n in-state= %d  in-symbol= %c  out-state= %d",state,str[i],2);state=2;}
		if(state==2 && str[i]=='b')
{			printf("\n in-state= %d  in-symbol= %c  out-state= %d",state,str[i],3);state=3;}

		if(state==3 && str[i]=='a')
{			printf("\n in-state= %d  in-symbol= %c  out-state= %d",state,str[i],2);state=2;}
		if(state==3 && str[i]=='b')
{			printf("\n in-state= %d  in-symbol= %c  out-state= %d",state,str[i],4);state=4;break;}
		i++;
	}

if(state==4 && i==len)
	printf("\n Accepted ... \n ");
else
	printf("\n Rejected ... \n ");

}



			
	

