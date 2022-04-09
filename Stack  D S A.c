#include<stdio.h>
#include<stdlib.h>
void push(int );
void pop();
void peek();
void traversal();
int isFull();
int isEmpty();
#define N 5
int stack[N];
int top=-1;
void push(int num)
{
 if(isFull())
 {
  printf("Stack Is Overflowed");
 }
 else
 {
  top=top+1;
  stack[top]=num;
 }
}
int isFull()
 { 
  if(top==N-1)
  return 1;
  return 0;
 }
void pop()
{
 if(isEmpty())
 {
  printf("Stack Is Underflowed");
 }
 else
 {
  printf("poped Element is %d",stack[top]);
  top=top-1;
 }
}

}
void peek()
{
 if(isEmpty())
 {
  printf("stack Is Underflow");
 }
 else
 {
  printf("Top Most Element in The Stack is %d",stack[top]);
 }
}
void traversel()
{
  int i;
 if(isEmpty())
 {
  printf("Stack Is Underflow");
 }
 else
 {
   printf("The Stack Elements Are:- \n");
   for(i=0;i<=4;i++)
   {
     printf("%d ",stack[i]);
   }
 }
} 
int isEnpty()
{
 if(top==-1)
  return 1;
  return 0;

int main()
{
  int n,num;
  while(1)
  {
     printf("Press 1 For push\n");
     printf("Press 2 For pop\n");
     printf("Press 3 For peek\n");
     printf("Press 4 For Traversal\n");
     printf("Press 5 For Exit");
     scanf("%d",&n);
     switch(n)
     {
         case 1:
         {
          printf("Enter The Element for pussing:- ");
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
		   break;
		 }
		 default :
		 {
		  printf("Enter a Valid Option");
		 }
	 }
  }
 }
