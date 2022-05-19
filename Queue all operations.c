#include<stdio.h>
#include<stdlib.h>
#define max 5
int queue[max];
int front = -1;
int rear = -1;
void enqueue();
void dequeue();
void display();
void peek();
int main()
{
   int n;
   while(1)
   {
	 printf("\n1: for enque\n");
	 printf("2: for dequeue\n");
	 printf("3: for display\n");
	 printf("4: for peek\n");
	 printf("5: for exit\n");
	 scanf("%d",&n);
	 switch(n)
	 {
	   case 1:
	   {
		 enqueue();
		 break;
	   }
	   case 2:
	   {
		 dequeue();
		 break;
	   }
	   case 3:
	   {
		 display();
		 break;
	   }
	   case 4:
	   {
		 peek();
		 break;
	   }
	   case 5:
	   {
		 exit(0);
	   }
	   default:
	   {
		 printf("Please enter a valid option\n");
	   }
	 }
   }
}
void enqueue()
{
   int data;
   if(rear==max-1)
   {
	 printf("Queue is in overflow condition\n");
   }
   else
   {
	 if(front ==-1)
	 {
	   front++;
	 }
	 printf("Enter the data for enqueue in the queue:- ");
	 scanf("%d",&data);
	 rear++;
	 queue[rear]=data;
   }
}
void display()
{
  if(front ==-1)
  {
	printf("Queue is in underflow condition\n");
  }
  else
  {
	 int i, n = front;
	 printf("Data presents in the queue :- ");
	 for(i=n;i<=rear;i++)
	 {
	   printf("%d\t",queue[i]);
	 }
  }
}
void dequeue()
{
   if(front>rear||front==-1)
   {
	  printf("Queue is in underflow condition\n");
   }
   else
   {
	 printf("Dequeue data is :- %d",queue[front]);
	 front++;
   }
}
void peek()
{
  if(front==-1)
  {
	printf("Queue is in underflow condition\n");
  }
  else
  {
	printf("The peek data of the queue is:- %d",queue[front]);
  }
}
