#include<stdio.h>
#include<stdlib.h>
void enqueue();
void dequeue();
void display();
#define max 5
int front = -1;
int rear = -1;
int queue[max];
int main()
{
   int ch;
   while(1)
   {
	 printf("\nPress 1 for enqueue\n");
	 printf("press 2 for dequeue\n");
	 printf("press 3 for display\n");
	 scanf("%d",&ch);
	 switch(ch)
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
	 }
   }
}
void enqueue()
{
  int data;
  if(rear==max-1)
  {
	printf("Queue is full\n");
  }
  else
  {
	if(front==-1)
	{
	  front = front+1;
	}
	printf("Enter the data:- ");
	scanf("%d",&data);
	rear = rear+1;
	queue[rear] = data;
  }
}
void display()
{
 int i;
 if(front>rear)
  {
	 printf("Queue is empty\n");
  }
  else
  {
	printf("Queue elements are:- ");
    for(i=front;i<=rear;i++)
     {
	   printf("%d\t",queue[i]);
     }
  }
}
void dequeue()
{
   if(front==-1||front>rear)
   {
	 printf("Queue is empty\n");
   }
   else
   {
	 printf("Dequeue element = %d",queue[front]);
	 front = front+1;
   }
}
