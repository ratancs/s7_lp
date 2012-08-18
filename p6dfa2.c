// program to chek regular expression for a grammar (a+b+c)*abc
// in-state	input	out-state
//	1	a  	2		
//	1	b	1
//	1	c	1
//	2	a	2
//	2	b	3
//	2	c	1
//	3	a	2
//	3	b	1	
//	3	c	4

#include<stdio.h>
#include<string.h>

void main()
{
	int state=1,len,i=0;
	char str[50];
	printf("\n Enter Expression : ");
	gets(str);
	len=strlen(str);

	while(i<len)
	{
		if(state==1 && str[i]=='a')
{			printf("\n in-state= %d  in-symbol= %c  out-state= %d",state,str[i],2);state=2;}
		else if(state==1 && str[i]=='b')
{			printf("\n in-state= %d  in-symbol= %c  out-state= %d",state,str[i],1);state=1;}
		else if(state==1 && str[i]=='c')
{			printf("\n in-state= %d  in-symbol= %c  out-state= %d",state,str[i],1);state=1;}

		else if(state==2 && str[i]=='a')
{			printf("\n in-state= %d  in-symbol= %c  out-state= %d",state,str[i],2);state=2;}
		else if(state==2 && str[i]=='b')
{			printf("\n in-state= %d  in-symbol= %c  out-state= %d",state,str[i],3);state=3;}
		else if(state==2 && str[i]=='c')
{			printf("\n in-state= %d  in-symbol= %c  out-state= %d",state,str[i],1);state=1;}

		else if(state==3 && str[i]=='a')
{			printf("\n in-state= %d  in-symbol= %c  out-state= %d",state,str[i],2);state=2;}
		else if(state==3 && str[i]=='b')
{			printf("\n in-state= %d  in-symbol= %c  out-state= %d",state,str[i],1);state=1;}
		else if(state==3 && str[i]=='c')
{			printf("\n in-state= %d  in-symbol= %c  out-state= %d",state,str[i],4);state=4;}
		i++;
	}	



if(state==4 && i==len)
	printf("\n Accepted ... \n ");
else
	printf("\n Rejected ... \n ");

}

