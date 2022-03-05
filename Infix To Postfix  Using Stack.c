#include<stdio.h>
#include<string.h>
#include<ctype.h>
void push(char);
char pop();
int priority(char);
int isFull();
int isEmpty();
#define N 20
char stack[N];
int top = -1;
char x;
int main()
{
  char infix[100],ele,n;
  int i;
  printf("Enter The Infix Expretion:- ");
  scanf("%s",infix);
  printf("\nThe Infix Expretion Is %s\n",infix);
 int b= strlen(infix);
 i=0;
    printf("\nPostfix Expretion Is:- ");
  while(i<b)
  {
     ele = infix[i];
    if(isalnum(ele))
    {
      printf("%c",ele);
	}
	if(ele == '(')
	{
	  push(ele);
	}
	if(ele == ')')
	{
	  while((n=pop())!= '(')
	  {
	    printf("%c",n);
	  }
	}
	if(ele == '^' || ele == '*' || ele == '/' || ele == '+' || ele == '-'  ) 
	{
	  if(isEmpty())
	  {
	    push(ele);
	  }
	  else
	  {
	      while(priority(stack[top])>=priority(ele))
	     {
	        n=pop();
	        printf("%c",n);
	     }
	     push(ele);
	  }
	}
	i++;
  }
  while(top != -1)
  {
     printf("%c",pop());
  }
}
int priority(char ch)
{
  if(ch== '^')
    return 3;
  if(ch== '*' || ch == '/')
    return 2;
  if(ch == '+' || ch == '-')
    return 1;
  if(ch == '(')
    return 0;
}
void push(char ele)
{
  if(isFull())
  {
    printf("\nStack Is Overflowed\n");
  }
  else
  {
    top=top+1;
    stack[top]= ele;
  }
}
char pop()
{
  if(isEmpty())
  {
    printf("\nStack Is Underflowed\n");
  }
  else
  {
    x=stack[top];
    top=top-1;
  }
  return x;
}
int isFull()
{
   if(top == N-1)
    return 1;
    return 0;
}
int isEmpty()
{
   if(top == -1)
     return 1;
     return 0;
}
