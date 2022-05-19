#include<stdio.h>
#include<stdlib.h>
void append();
void delete();
void display();
void append_at_any_pos();
void search();
void sort_ascending_linked();
void sort_descending_linked();
struct node
{
  int data;
  struct node* link;
};
struct node* head = NULL;
int main()
{
   int n;
   while(1)
   {
	  printf("\n**/ Options available **/");
	  printf("\n1: for append\n");
	  printf("2: for delete\n");
	  printf("3: for display\n");
	  printf("4: for append at any possition\n");
	  printf("5: for search a data\n");
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
		  delete();
		  break;
		}
		case 3:
		{
		  display();
		  break;
		}
		case 4:
		{
		  append_at_any_pos();
		  break;
		}
		case 5:
		{
		  search();
		  break;
		}
		case 6:
		{
		  sort_ascending_linked();
		  break;
		}
		case 7:
		{
		  sort_descending_linked();
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
   int data;
   struct node* newnode = NULL;
   newnode = (struct node*)malloc(sizeof(struct node));
   printf("Enter the data:- ");
   scanf("%d",&newnode->data);
   newnode->link = NULL;
   if(head==NULL)
   {
	  head = newnode;
   }
   else
   {
	  struct node* p = head;
	  while(p->link!=NULL)
	  {
		p = p->link;
	  }
	  p->link = newnode;
   }
}
void delete()
{
   if(head==NULL)
  {
	printf("List is empty");
  }
  else
  {
	 int pos;
   printf("Enter the possition:- ");
   scanf("%d",&pos);
   int len = length();
   if(pos>len)
   {
	  printf("Possition not found in the list\n");
   }
   else if(pos == 1)
   {
	 struct node* p = head;
	 head = p->link;
	 p->link = NULL;
	 free(p);
   }
   else if(pos==len)
   {
	 struct node* p = head,* q;
	 while(p->link!=NULL)
	 {
	   q = p;
	   p = p->link;
	 }
	 q->link = NULL;
	 free(p);
   }
   else
   {
	 int i = 1;
	 struct node* p = head,* q = NULL,* r = NULL;
	 while(i<pos)
	 {
		q = p;
		p = p->link;
		i++;
	 }
	 r = p->link;
	 p->link = NULL;
	 q->link = r;
	 free(p);
   }
  }
}
int length()
{
  int count = 0;
  if(head == NULL)
  {
	printf("List is empty");
  }
  else
  {
	struct node* p = head;
	while(p!=NULL)
	{
	  count ++;
	  p = p->link;
	}
	return count;
  }
}
void display()
{
  if(head == NULL)
  {
	printf("List is empty");
  }
  else
  {
	struct node* p = head;
	printf("Data in the list :- ");
	while(p!=NULL)
	{
	  printf("%d\t",p->data);
	  p = p->link;
	}
  }
}
void append_at_any_pos()
{
   if(head==NULL)
   {
	 printf("List is empty");
   }
   else
   {
	 int pos;
   printf("Enter the possition:- ");
   scanf("%d",&pos);
   struct node* newnode = NULL;
   newnode = (struct node*)malloc(sizeof(struct node));
   newnode->link = NULL;
   int len = length();
   if(pos>len)
   {
	 printf("Possition not found in the list");
   }
   else if(pos==1)
   {
	 printf("Enter the data:- ");
	 scanf("%d",&newnode->data);
	 newnode->link = head;
	 head = newnode;
   }
   else
   {
	 printf("Enter the data:- ");
	 scanf("%d",&newnode->data);
	 int i = 1;
	 struct node* p = head,* q = NULL;
	 while(i<pos-1)
	 {
	   p= p->link;
	   i++;
	 }
	 q = p->link;
	 p->link = newnode;
	 newnode->link = q;
   }
   } 
}
void search()
{
  int data,loc= 1;
  if(head==NULL)
  {
	printf("List is empty");
  }
  else
  {
	 printf("Enter the data");
	 scanf("%d",&data);
	 struct node* p = head;
	 while(p!=NULL)
	 {
		if(p->data==data)
		{
		   printf("Data present in the :- %d location",loc);
		}
		p = p->link;
	    loc++;
	 }
  }
}
void sort_ascending_linked()
{
   struct node* p = head,*q = NULL;
   int temp;
   if(head==NULL)
   {
	 printf("List is empty");
   }
   else 
   {
	  for(p=head;p->link!=NULL;p=p->link)
	  {
		for(q=p->link;q!=NULL;q=q->link)
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
void sort_descending_linked()
{
  struct node* p = NULL,* q = NULL;
  int temp;
  if(head==NULL)
  {
	printf("List is empty\n");
  }
  else
  {
	 for(p=head;p->link!=NULL;p=p->link)
	  {
		for(q=p->link;q!=NULL;q=q->link)
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
