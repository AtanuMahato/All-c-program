#include<stdio.h>
#include<stdlib.h>
void append();
void display();
void add_at_anypos();
struct node
{
  int data;
  struct node* link;
};
struct node* root = NULL,* temp = NULL;
int main()
{
  int n;
  while(1)
  {
	printf("\nEnter 1 for append\n");
    printf("Enter 2 for display\n");
    printf("Enter 3 for add_at_anypos\n");
    printf("Enter 4 for length\n");
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
		add_at_anypos();
		break;
	  }
	  case 4:
	  {
		printf("length=%d",length());
		break;
	  }
	}
  }
}
void append()
{
   struct node* newnode;
   newnode = (struct node*)malloc(sizeof(struct node));
   printf("Enter the data :- ");
   scanf("%d",&newnode->data);
   newnode->link = NULL;
   if(root==NULL)
   {
	  root = newnode;
	  temp = newnode;
   }
   else
   {
	 temp->link = newnode;
	 temp = newnode;
   }
   temp->link = root;
}
void display()
{
  struct node* p = root;
  if(root == NULL)
  {
	printf("List is empty\n");
  }
  else
  {
	while(p->link!=root)
	{
	  printf("%d\n",p->data);
	  p = p->link;
	}
	printf("%d\n",p->data);
  }
}
void add_at_anypos()
{
  int pos;
  int len = length();
  printf("Enter the possition:- ");
  scanf("%d",&pos);
  if(pos>len)
  {
	printf("possition not present in the list\n");
  }
  else if(pos==1)
  {
	 struct node* newnode;
	 newnode = (struct node*)malloc(sizeof(struct node));
	 printf("Enter the data:- ");
	 scanf("%d",&newnode->data);
	 newnode->link = root;
	 temp->link = newnode;
	 root = newnode;
  }
  else if(pos==length())
  {
	struct node* newnode = NULL;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data:- ");
	scanf("%d",&newnode->data);
	newnode->link = NULL;
	temp->link = newnode;
	newnode->link = root;
	temp = newnode;
  }
  else
  {
	 int i= 1;
	 struct node* newnode,* p = root,* q = NULL;
	 newnode = (struct node*)malloc(sizeof(struct node));
	 printf("Enter the data:- ");
	 scanf("%d",&newnode->data);
	 newnode->link = NULL;
	 while(i<pos)
	 {
	   p = p->link;
	   i++;
	 }
	 q = p->link;
	 p->link = newnode;
	 newnode->link = q;
  }
}
int length()
{
   int i = 0;
  struct node* p = root;
  if(root==NULL)
  {
	printf("List is empty\n");
  }
  else
  {
	while(p->link!=root)
	{
	  i++;
	  p = p->link;
	}
  }
  return i+1;
}
