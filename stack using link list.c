#include<stdio.h>
#include<stdlib.h>
void push();
void display();
void pop();
void peek();
struct node
{
  int data;
  struct node* link;
};
struct node* head = NULL,* tail = NULL;
int main()
{
  int n;
  while(1)
  {
	printf("\n1:for push\n");
	printf("2:for pop\n");
	printf("3:for display\n");
	printf("4:for peek\n");
	printf("5:for exit\n");
	scanf("%d",&n);
	switch(n)
	{
	  case 1:
	  {
		push();
		break;
	  }
	  case 2:
	  {
		pop();
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
void push()
{
  struct node* newdata = NULL;
  newdata = (struct node*)malloc(sizeof(struct node));
  printf("Enter the data:-");
  scanf("%d",&newdata->data);
  newdata->link = NULL;
  if(head==NULL)
  {
	head = newdata;
	tail = newdata;
  }
  else
  {
	tail->link = newdata;
	tail = newdata;
  }
}
void display()
{
  if(head==NULL)
  {
	printf("Stack is in Underflow condition\n");
  }
  else
  {
	printf("Data presents in the stack :- ");
    struct node* p = head;
    while(p!=tail)
    {
	  printf("%d\t",p->data);
	  p = p->link;
    }
    printf("%d\t",p->data);
  }
}
void pop()
{
   if(head==NULL)
   {
	 printf("\nStack is in underflow condition\n");
   }
   else if(head==tail)
   {
	 printf("Poped data is:- %d",tail->data);
	 tail = NULL;
	 head = NULL;
	 free(tail);
   }
   else
   {
	printf("Poped data is:- %d",tail->data);
	 struct node* p = head,* temp = tail;
	 while(p->link!=tail)
	 {
	   p = p->link;
	 }
	 p->link = NULL;
	 free(temp);
	 tail = p;
   }
}
void peek()
{
  if(head==NULL)
  {
	printf("Stack is in underflow condition\n");
  }
  else
  {
	printf("Peak data of the stack= %d",tail->data);
  }
}
