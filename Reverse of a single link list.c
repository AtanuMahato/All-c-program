#include<stdio.h>
#include<stdlib.h>
void append();
void display();
void reverse();
struct node
{
  int data;
  struct node* link;
};
struct node* root = NULL;
int main()
{
int n;
while(1)
 {
   printf("\nPress 1 for append\n");
   printf("Press 2 for display\n");
   printf("Press 3 for revers\n");
   scanf("%d",&n);
   switch(n)
   {
	 case 1:
	 {
	   append();
	   break;
	 }
	 case 2:
	 {
	   display();
	   break;
	 }
	 case 3:
	 {
	   reverse();
	   break;
	 }
   }
 }
}
void append()
{
  struct node* temp;
  temp =(struct node*)malloc(sizeof(struct node));
  printf("Enter the data:- ");
  scanf("%d",&temp->data);
  temp->link = NULL;
  if(root==NULL)
  {
	root = temp;
	printf("\nData inserted\n");
  }
  else
  {
	struct node* p = root;
	while(p->link!=NULL)
	{
	  p = p->link;
	}
	p->link = temp;
    printf("\nData inserted\n");
  }
}
void display()
{
  if(root==NULL)
  {
	printf("List is empty\n");
  }
  else
  {
	printf("Data:- ");
    struct node* p = root;
	while(p!=NULL)
	{
	  printf("%d\t",p->data);
	  p = p->link;
	}
  }
}
void reverse()
{
    struct node* previous_node = NULL,* current_node,* next_node;
	current_node=next_node= root;
	while(next_node!=NULL)
	{
	  next_node = next_node->link;
	  current_node->link = previous_node;
	  previous_node = current_node;
	  current_node = next_node;
	}
	root = previous_node;
}
