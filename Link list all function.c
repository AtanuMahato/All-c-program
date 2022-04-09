#include<stdio.h>
#include<stdlib.h>
void append();
void display();
void delete();
int length();
void add_node();
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
	printf("\nEnter 1 for append\n");
    printf("Enter 2 for display\n");
    printf("Enter 3 for delete\n");
    printf("Enter 4 for add a node\n");
    printf("Enter 5 for exit\n");
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
	  delete();
	  break;
	}
	case 4:
	{
	  add_node();
	  break;
	}
	case 5:
	{
	  exit(0);
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
int length()
{
  int count = 0;
  struct node* p = root;
  if(root==NULL)
  {
	printf("List is empty\n");
  }
  else
  {
	 while(p!=NULL)
	 {
		count++;
		p = p->link;
	 }
  }
  return count;
}
void delete()
{
   int pos;
   int len=length();
   struct node* p = root,* q;
   if(root==NULL)
   {
	  printf("List is empty\n");
   }
   else
   {
	 printf("Enter the node possition\n");
	 scanf("%d",&pos);
	 if(pos>len)
	 {
	   printf("Node is not present in the list\n");
	   printf("Now %d nodes are present in the list\n",len);
	 }
	 else if(pos==1)
	 {
		 root=p->link;
		 free(p);
	 }
	 else
	 {
	   int i=1;
	   while(i<pos-1)
	   {
		 p=p->link;
		 i++;
	   }
	   q = p->link;
	   p->link = q->link;
	   q->link = NULL;
	   free(q);
	 }
   }
}
void add_node()
{
  struct node* p = root,* temp;
  temp=(struct node*)malloc(sizeof(struct node));
  int len = length();
  int pos,i=1;
  printf("Enter the position:- ");
  scanf("%d",&pos);
  if(pos==1)
  {
	printf("Enter the data:- ");
	scanf("%d",&temp->data);
	temp->link=root;
	root=temp;
  }
  else
  {
	 printf("Enter the data:- ");
	 scanf("%d",&temp->data);
	 temp->link = NULL;
	 while(i<pos-1)
	 {
	   p = p->link;
	   i++;
	 }
	 temp->link = p->link;
	 p->link = temp;
	 
  }
}
