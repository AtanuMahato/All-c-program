#include<stdio.h>
#include<stdlib.h>
#define N 10
void push(char);
void pop();
void check_exp();
char stack[N];
int top = -1;
int main()
{
  int n=1;
	 int i;
     char exp[100];
     printf("Enter a arithmetic expression:- ");
     gets(exp);
     for(i=0;exp[i]!='\0';i++)
     {
	   if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
	   {
	     push(exp[i]);
	   }
	   else if(exp[i]==')'||exp[i]=='}'||exp[i]==']')
	   {
	     pop();
	   }
     }
     check_exp();
}
void push(char n)
{
  top = top+1;
  stack[top]=n;
}
void pop()
{
  if(top == -1)
  {
	printf("Expression is not properly parenthesized");
	exit(0);
  }
  else
  {
	top = top-1;
  }
}
void check_exp()
{
  if(top==-1)
  {
	printf("Expression is properly parenthesized");
  }
  else
  {
	printf("Expression is not properly parenthesized");
  }
}
