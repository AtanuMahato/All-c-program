#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node* link;
};
struct node* stack_1_head = NULL;
struct node* stack_2_head = NULL;
void push_stack_1( int );
int pop_stack_1();
void push_stack_2( int );
void pop_stack_2();
void display();
int length();
int main()
{
  int choice , data;
  printf("\t Queue implementation using stack\n");
  while(1)
  {
	printf("\n ||  1 for enqueue    ||\n");
	printf(" ||  2 for dequeue    ||\n");
	printf(" ||  3 for exit       ||\n");
	printf("\n Enter your choice:- ");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
		{
		  printf("\nEnter the data for enqueue into the queue:- ");
		  scanf("%d",&data);
		  push_stack_1(data);
		  break;
		}
		case 2:
		{
		  int pop_data;
		  int len = length();
		  if(stack_1_head!=NULL)
		  {
		    while(len)
		    {
			 pop_data = pop_stack_1();
		     push_stack_2(pop_data);
		     len--;
            }
             stack_1_head = NULL;
		  }
		  pop_stack_2();
		  break;
		}
		case 3:
		{
		  exit (0);
		}
		default:
		{
		  printf("\nEnter a valid chooice");
		}
	}
  }
  return 0;
}
void push_stack_1(int value)
{
  struct node* new_node = NULL;
  struct node* temp = NULL;
  new_node = (struct node*)malloc(sizeof(struct node));
  new_node->data = value;
  new_node->link = NULL;
  if(stack_1_head == NULL){
	stack_1_head = new_node;}
  else{
	 temp = stack_1_head;
	 while(temp->link!=NULL)
	 {
	   temp = temp->link;
	 }
	 temp->link = new_node;
	}
}
int pop_stack_1()
{
   int data;
   struct node *p , *q;
   p = stack_1_head;
   while(p->link!=NULL)
   {
	  q = p;
	  p = p->link;
   }
   data = p->data;
   q->link = NULL;
   free(p);
   return data;
}
void push_stack_2(int value)
{
  struct node* new_node = NULL;
  struct node* temp = NULL;
  new_node = (struct node*)malloc(sizeof(struct node));
  new_node->data = value;
  new_node->link = NULL;
  if(stack_2_head == NULL)
	stack_2_head = new_node;
  else
  {
	temp = stack_2_head;
	while(temp->link!=NULL){
	 temp = temp->link;}
	 temp->link = new_node;
  }
}
void pop_stack_2()
{
   if(stack_2_head==NULL)
   {
	  printf("\n || Queue underflow ||\n");
   }
   else
   {
      struct node *p , *q;
      p = stack_2_head;
      while(p->link!=NULL)
      {
	    q = p;
	    p = p->link;
      }
      if(p==stack_2_head)
      {
	    printf("\n dequeue data is %d\n",p->data);
	    stack_2_head = NULL;
	    free(stack_2_head);
      }
      else
      {
        printf("\n dequeue data is %d\n",p->data);
        q->link = NULL;
        free(p);
      }
   }
}
int length()
{
  int i=0;
  struct node* p =stack_1_head;
  while(p!=NULL)
  {
	i = i+1;
	p = p->link;
  }
  return i;
}

















