#include<stdio.h>
#include<stdlib.h>
void append();
void display();
void delete_node();
struct node
{
  int data;
  struct node* link;
};
struct node* root = NULL;
int main()
{
   while(1)
   {
   int n;
   printf("\nEnter 1 for append\n");
   printf("Enter 2 for display\n");
   printf("Enter 3 for delete\n");
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
	   delete_node();
	   break;
	 }
   }
   }
}
void append()
{
struct node* temp = NULL;
temp = (struct node*)malloc(sizeof(struct node));
printf("Enter the data:- ");
scanf("%d",&temp->data);
temp->link = NULL;
 if(root==NULL)
 {
   root = temp;
 }
 else
 {
	struct node* p = root;
	while(p->link!=NULL)
	{
	  p = p->link;
	}
	p->link = temp;
 }
}
void display()
{
  struct node* p = root;
  while(p!=NULL)
  {
	printf("%d\t",p->data);
	p = p->link;
  }
}
void delete_node()
{
  int ele;
  printf("Enter the element:- ");
  scanf("%d",&ele);
  struct node* p = root,* q = NULL,* r = NULL;
  while(p->data!=ele)
  {
	 q = p;
	 p = p->link;
  }
  r = p->link;
  if(p==root)
  {
   p->link = NULL;
   root = r;
   free(p);
  }
  else if(p->link==NULL)
  {
	q->link = NULL;
	free(p);
  }
  else
  {
	q->link = r;
	p->link = NULL;
	free(p);
  }
}
