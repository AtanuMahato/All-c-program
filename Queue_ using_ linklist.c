#include<stdio.h>
#include<stdlib.h>
void enqueue();
void dequeue();
void display();
struct queue
{
   int data;
   struct queue* link;
};
struct queue* front = NULL,* rear = NULL;
int main()
{
   int n;
   while(1)
   {
	  printf("\nPress 1 for enqueue\n");
	  printf("Press 2 for dequeue\n");
	  printf("Press 3 for display\n");
	  printf("Press 4 for exit\n");
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
			  exit(0);
		  }
      }
   }
}
void enqueue()
{
  struct queue* new_ele = NULL;
  new_ele = (struct queue*)malloc(sizeof(struct queue));
  printf("Enter the data:- ");
  scanf("%d",&new_ele->data);
  new_ele->link = NULL;
  if(front==NULL)
  {
	front = new_ele;
	rear = new_ele;
  }
  else
  {
        rear->link = new_ele;
	rear = new_ele;
  }
}
void dequeue()
{
  struct queue* p = front;
  {
	printf("Queue is empty\n");
  }
  else
  {
	printf("Dequeue element is %d\n",p->data);
	front = p->link;
	p->link = NULL;
	free(p);
  }
}
void display()
{
   if(front==NULL)
   {
	 printf("queue is empty\n");
   }
   else
   {
	 struct queue* p = front;
	 while(p!=NULL)
	  {
	   printf("%d\t",p->data);
	   p = p->link;
	  }
   }
}
