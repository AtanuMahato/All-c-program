#include<stdio.h>
#include<stdlib.h>
#define max 5
void enqueue();
void dequeue();
void display();
void peek();
int queue[max];
int front = -1;
int rear = -1;
int main()
{
  int n;
  while(1)
  {
	printf("\n1: for enqueue\n");
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
	  case 5:
	  {
		exit(0);
	  }
	  case 4:
	  {
		peek();
		break;
	  }
	}
  }
}
void enqueue()
{
  int data;
  if(front==-1&&rear==-1)
  {
	printf("Enter the data:- ");
	scanf("%d",&data);
	front=rear=0;
	queue[rear]=data;
  }
  else if((rear+1)%max==front)
  {
	printf("Circular queue is full\n");
  }
  else
  {
	printf("Enter the data:- ");
	scanf("%d",&data);
	rear = (rear+1)%max;
	queue[rear] = data;
  }
}
void dequeue()
{
  if(front==-1&&rear==-1)
  {
	printf("circular queue is empty\n");
  }
  else if(front == rear)
  {
	printf("Dequeue data is %d",queue[front]);
	front = rear = -1;
  }
  else
  {
	printf("Dequeue data is %d",queue[front]);
	front = (front+1)%max;
  }
}
void display()
{
  int i = front;
  if(front==-1&&rear==-1)
  {
	printf("Circular queue is empty\n");
  }
  else
  {
	while(i!=rear)
	{
	  printf("%d\t",queue[i]);
	  i =(i+1)%max;
	}
	printf("%d\t",queue[rear]);
  }
}
void peek()
{
    if(front==-1&&rear==-1)
    {
	printf("Circular queue is empty\n");
    }
    else
    {
	  printf("Peek data of the circular queue is %d",queue[front]);
	}
}
