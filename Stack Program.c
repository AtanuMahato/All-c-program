#include<stdio.h>
#include<stdlib.h>
void push(int);
void pop();
void peek();
void traversal();
int isFull();
int isEmpty();
#define N 5
int stack[N];
int top=-1;
int main()
{
     int n,num;
     while(1)
     {
         printf("\nPress 1 For push\n");
         printf("Press 2 For pop\n");
         printf("Press 3 For peek\n");
         printf("Press 4 For traversal\n");
         printf("Press 5 For Exit\n");
   scanf("%d",&n);
     
     switch(n)
     {
       case 1:
         {
          printf("Enter The Element For push in The Stack:- ");
          scanf("%d",&num);
          push(num);
          break;
		 }
	   case 2:
	     {
	      pop();
	      break;
		 }
	   case 3:
	     {
	      peek();
	      break;
		 }
	   case 4:
	     {
	      traversal();
	      break;
		 }
	   case 5:
	    {
	     exit(0);
	    }
	   default:
	    {
	      printf("Enter A Valid Number ||");
	    }
	 }
	}
}
void push(int num)
{
    if(isFull())
    {
      printf("Stack is Overflow ||\n");
	}
	else
	{
	  top=top+1;
	  stack[top]=num;
	}
}
void pop()
{
  if(isEmpty())
  {
    printf("Stack is Underflow ||\n");
  }
  else
  {
    printf("Poped Element is %d ",stack[top]);
    top=top-1;
  }
}
void peek()
{
  if(isEmpty())
  {
    printf("Stack is Underfload ||\n");
  }
  else
  {
    printf("The Top Element Is %d ",stack[top]);
  }
}
void traversal()
{
  if(isEmpty())
  {
    printf("Stack is Underflowed||\n");
  }
  else
  {
    int i;
    printf("Stack Elements are:- \n");
    for(i=0;i<=N-1;i++)
    {
     printf("%d ",stack[i]);
	}
  }
}
int isFull()
{
    if(top==4)
     return 1;
     return 0;
}
int isEmpty()
{
    if(top==-1)
      return 1;
      return 0;
}
