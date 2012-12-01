#include<stdio.h>
#include<string.h>
     
 char table[4][4]={'0','>','>','>',
		     	'<','>','<','>',
		     	'<','>','>','>',
		     	'<','<','<','0'};

char table_order[4]={'i','+','*','$'};

char stack[100];
int stkres[100];

int stkptr=-1,stkrptr=-1;

void push(char a)
{ stack[++stkptr]=a;}
char pop()
{	return stack[stkptr--];}
char peek()
{	return stack[stkptr];}
void pushres(int a)
{	stkres[++stkrptr]=a;}
int popres()
{	return stkres[stkrptr--];}


int preced(char a,char b)
{
	int i,j;
	for(i=0;i<4;i++)
		if(table_order[i]==a)	
			break;
	for(j=0;j<4;j++)
		if(table_order[j]==b)
			break;


	if(i==4||j==4)
		error();
	else{
	if(table[i][j]=='<')
		return 0;
	else if(table[i][j]=='>')
		return 1;
	else
		return 2;
		
	}
}
	
void error()
{
	printf("Error");
	exit(0);
}



void main()
{

	char str[100],temp;
	int len,inp_ptr=0,f,prec,no;
	printf("\nEnter the expression :");
	scanf("%s",str);
	push('$');
	len=strlen(str);
	str[len]='$';
	str[len+1]='\0';
	puts(str);
	while(str[inp_ptr]!='$'|| peek()!='$')
	{
		f=0;
		printf("\nin the while");


		if(str[inp_ptr]>='0'&&str[inp_ptr]<='9'){
			no=atoi(&str[inp_ptr++]);	
				printf("#####%d###",no);
			while(str[inp_ptr]<='0'&&str[inp_ptr]>='9')
				inp_ptr++;
			str[inp_ptr--]='i';
			f=1;
			}

	prec=preced(peek(),str[inp_ptr]);
	printf("@@%d@@",prec);
	printf("reached here1");
	if(prec==0)
	{
		if(f==1)
			pushres(no);
		push(str[inp_ptr++]);
	}
	else if(prec==1)
	{
	do{
	temp=pop();
	printf("reached here<F2>");
	switch(temp){
	case '+':	pushres(popres()+popres());break;
	case '*':	pushres(popres()*popres());break;
		    }
	}while(preced(peek(),temp)!=0);
	}	
	else
		error();
}
	printf("Result=%d\n",popres());
}
		

			
	
