		/*Program to convert infix equation to postfix using stack*/
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<dos.h>
int priority(char ch)
{
	if(ch=='^')
		return(5);
	else if(ch=='/'||ch=='*')
		return(4);
	else if(ch=='+'||ch=='-')
		return(3);
	else
		return(2);
}
int isOperator(char ch)
{
	if(ch=='^'||ch=='+'||ch=='-'||ch=='*'||ch=='/')
		return(1);
	else
		return(0);
}
void main()
{
clrscr();
char q[50],p[50],stack[50];
int top=-1, k=0,l=0,x1=1,x2=25,x3=50,y=2,j,flag=0;
printf("Enter infix Equation: ");
scanf("%s",&q);
char part[10];
int i=0;
p[0]='\0';
stack[0]='\0';
gotoxy(x1,y);
//conio
textcolor(BLUE);
	cprintf("Scaned: ");
gotoxy(x2,y);
textcolor(RED);
	cprintf("Stack: ");
gotoxy(x3,y);
textcolor(GREEN);
	cprintf("Postfix: ");
y+=1;

while(q[i]!='\0')
{
	k=0;
	delay(500);
	gotoxy(x1,y);
	textcolor(BLUE);
	cprintf("%c",q[i]);
	if(isalpha(q[i])||isdigit(q[i]))
	{      part[k]=q[i];
		i++;
		part[++k]='\0';
		l=strlen(p);
		for(int s=0;s<k;s++)
		{
			p[l++]=part[s];
		}
		p[l]='\0';
		k=0;
		flag=0;
	}
	else if(q[i]=='(')
	{
	  stack[++top]=q[i];
	  stack[top+1]='\0';
	  flag=1;
	  i++;
	}
	else if(q[i]==')')
	{
		flag=2;
	  l=strlen(p);
	  while(stack[top]!='(')
	  {
	       p[l++]=stack[top--];

	  }
	  p[l]='\0';
	  top--;
	  stack[top+1]='\0';
	  i++;
	}
	else if(isOperator(q[i]))
	{
		flag=1;
		if(top!=-1)
		{
			l=strlen(p);
			if(priority(stack[top])>=priority(q[i]))
			{
				p[l++]=stack[top--];
				p[l]='\0';
				stack[top+1]='\0';

			}
			stack[++top]=q[i];
			stack[top+1]='\0';
		}
		else
		{
			stack[++top]=q[i];
			stack[top+1]='\0';
		}
		i++;
	}


if(flag==0)
{
	textcolor(RED);
	delay(100);
	gotoxy(x2,y);
	cprintf("%s",stack);
	delay(100);
	for(j=0;j<strlen(p);j++)
	{
		textcolor(GREEN);
		gotoxy(x3+j,y);
		cprintf("%c",p[j]);
		delay(500);
	}


}
else if(flag==1)
{
	for(j=0;j<strlen(stack);j++)
	{
		textcolor(RED);
		gotoxy(x2+j,y);
		cprintf("%c",stack[j]);
		delay(500);
	}
	textcolor(GREEN);
	gotoxy(x3,y);
	cprintf("%s",p);
	delay(100);
}
else
{
	for(j=0;j<strlen(stack);j++)
	{
		textcolor(RED);
		gotoxy(x2+j,y);
		cprintf("%c",stack[j]);
		delay(500);
	}
	for(j=0;j<strlen(p);j++)
	{
		textcolor(GREEN);
		gotoxy(x3+j,y);
		cprintf("%c",p[j]);
		delay(500);
	}

}
y++;
}
if(top!=-1)
{
	l=strlen(p);
	while(top>=0)
	{
		p[l++]=stack[top--];
	}
	p[l]='\0';

}
gotoxy(1,y);
printf("\nPostfix Eq: ");
cprintf("%s",p);
getch();
}