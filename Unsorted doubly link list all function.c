#include<stdio.h>
#include<stdlib.h>
void append();
void display();
int length();
void delete();
void append_at_anypos();
void sort_ascending_doubly_linked();
void sort_descending_doubly_linked();
struct node
{
  struct node* left;
  int data;
  struct node* right;
};
struct node* root = NULL;
int main()
{
  int len;
  while(1)
  {
	int n;
	printf("\n1: for append\n");
	printf("2: for display\n");
	printf("3: for length\n");
	printf("4: for delete\n");
	printf("5: for append at any possition\n");
	printf("6: for sort the linked list in ascending order\n");
	printf("7: for sort the linked list in descending order\n");
	printf("8: for exit\n");
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
		  len=length();
		  printf("Length of the linklist = %d\n",len);
		  break;
	   }
	   case 4:
	   {
		 delete();
		 break;
	   }
	   case 5:
	   {
		 append_at_anypos();
		 break;
	   }
	   case 6:
	   {
		 sort_ascending_doubly_linked();
		 break;
	   }
	   case 7:
	   {
		 sort_descending_doubly_linked();
		 break;
	   }
	   case 8:
	   {
		 exit(0);
	   }
	}
  }
}
void append()
{
   struct node* temp;
   temp= (struct node*)malloc(sizeof(struct node));
   printf("Enter the data:- ");
   scanf("%d",&temp->data);
   temp->left = NULL;
   temp->right = NULL;
   if(root==NULL)
   {
	 root=temp;
   }
   else
   {
	 struct node* p = root;
	 while(p->right!=NULL)
	 {
	   p = p->right;
	 }
	 p->right=temp;
	 temp->left=p;
   }
}
void display()
{
  struct node* p = root;
  if(root==NULL)
  {
	printf("List is empty");
  }
  else
  {
	printf("Data:- ");
	while(p!=NULL)
	{
		printf("%d\t",p->data);
		p = p->right;
    }
  }
}
int length()
{
  int i=0;
  struct node* p = root;
  if(root==NULL)
  {
	printf("list is empty\n");
  }
  else
  {
	while(p!=NULL)
	{
	  i++;
	  p = p->right;
	}
  }
  return i;
}
void delete()
{
   struct node* p = root,* q;
   int pos;
   int len=length();;
   printf("Enter the position:- ");
   scanf("%d",&pos);
   if(pos>len)
   {
	 printf("Element not present in the list\n");
   }
   else if(pos==1)
   {
		 q = p->right;
		 q->left = NULL;
		 root = q;
		 p->right = NULL;
		 free(p);
   }
   else if(pos==len)
   {
	 int i= 1;
	 while(i<len-1)
	 {
	   p = p->right;
	   i++;
	 }
	 q = p->right;
	 p->right = NULL;
	 free(q);
   }
   else
   {
	 int i=1;
	 while(i<pos-1)
	 {
	   p = p->right;
	 }
	 q = p->right;
	 p->right = q->right;
	 q->right = NULL;
	 free(q);
   }
}
void append_at_anypos()
{
   struct node* p = root;
   int pos,i=1;
   int len = length();
   printf("Enter the possition:- ");
   scanf("%d",&pos);
   if(pos>len)
   {
	 printf("node not present\n");
   }
   else if(pos == 1)
   {
	  struct node* temp;
	  temp = (struct node*)malloc(sizeof(struct node));
	  printf("Enter the data:- ");
	  scanf("%d",&temp->data);
	  temp->left = NULL;
	  temp->right = NULL;
	  if(root==NULL)
	  {
		printf("List is empty\n");
	  }
	  else
	  {
		struct node* p = root;
		temp->right = p;
		root = temp;
	  }
   }
   else
   {
	 struct node* temp,* q;
	 temp = (struct node*)malloc(sizeof(struct node));
	 printf("Enter the data:- ");
	 scanf("%d",&temp->data);
	 temp->left = NULL;
	 temp->right = NULL;
	 struct node* p = root;
	 int i= 1;
	 while(i<pos)
	 {
	   p = p->right;
	 }
	 q = p->right;
	 temp->right = q;
	 temp->left = p;
	 p->right = temp;
	 q->left = temp;
   }
}
void sort_ascending_doubly_linked()
{
   struct node* p = root,*q = NULL;
   int temp;
   if(root==NULL)
   {
	 printf("List is empty");
   }
   else
   {
	  for(p=root;p->right!=NULL;p=p->right)
	  {
		for(q=p->right;q!=NULL;q=q->right)
		{
		  if(p->data > q->data)
		  {
			   temp = p->data;
			   p->data = q->data;
			   q->data = temp;
		  }
		}
	  }
   }
}
void sort_descending_doubly_linked()
{
  struct node* p = NULL,* q = NULL;
  int temp;
  if(root==NULL)
  {
	printf("List is empty\n");
  }
  else
  {
	 for(p=root;p->right!=NULL;p=p->right)
	  {
		for(q=p->right;q!=NULL;q=q->right)
		{
		  if(p->data < q->data)
		  {
			   temp = p->data;
			   p->data = q->data;
			   q->data = temp;
		  }
		}
	  }
  }
}

