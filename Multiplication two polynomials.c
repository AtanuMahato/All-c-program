#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
  int expo;
  int coef;
  struct node* link;
};
struct node* head1 = NULL;
struct node* head2 = NULL;
struct node* head3 = NULL;
void append1(struct node* p,int coe_data,int exp_data)
{
  struct node* newnode = NULL;
  newnode = (struct node*)malloc(sizeof(struct node));
  newnode->coef = coe_data;
  newnode->expo = exp_data;
  newnode->link = NULL;
  if(p==NULL)
  {

	head1 = newnode;
  }
  else
  {
	 while(p->link!=NULL)
	 {
	   p = p->link;
	 }
	 p->link = newnode;
  }
}
void append2(struct node* p,int coe_data,int exp_data)
{
  struct node* newnode = NULL;
  newnode = (struct node*)malloc(sizeof(struct node));
  newnode->coef = coe_data;
  newnode->expo = exp_data;
  newnode->link = NULL;
  if(p==NULL)
  {

	head2 = newnode;
  }
  else
  {
	 while(p->link!=NULL)
	 {
	   p = p->link;
	 }
	 p->link = newnode;
  }
}
void append3(struct node* p,int coe_data,int exp_data)
{
  struct node* newnode = NULL;
  newnode = (struct node*)malloc(sizeof(struct node));
  newnode->coef = coe_data;
  newnode->expo = exp_data;
  newnode->link = NULL;
  if(p==NULL)
  {

	head3 = newnode;
  }
  else
  {
	 while(p->link!=NULL)
	 {
	   p = p->link;
	 }
	 p->link = newnode;
  }
}
void mul_two_polynomial(struct node* p1,struct node* p2)
{
  int mul_coef,add_expo;
  for(p1=head1;p1!=NULL;p1=p1->link)
  {
	for(p2=head2;p2!=NULL;p2=p2->link)
	{
	  mul_coef = p1->coef * p2->coef;
	  add_expo = p1->expo + p2->expo;
	  append3(head3,mul_coef,add_expo);
	}
  }
}
void display(struct node* p)
{
  while(p!=NULL)
  {
	printf("%dX^%d %c",p->coef,p->expo,p->link?'+':' ');
	p = p->link;
  }
}
int main()
{
   int n1,n2,max,coe_data,exp_data,max1;
   printf("Enter the degree of first polynomial:- ");
   scanf("%d",&n1);
   printf("Enter the degree of second polynomial:- ");
   scanf("%d",&n2);
   printf("Enter coefficients and Exponents of first polynomial....\n");
   printf("press any key to continue..\n");
   getch();
   while(n1+1)
   {
	 printf("Enter the coefficient:- ");
	 scanf("%d",&coe_data);
	 printf("Enter the Exponent:- ");
	 scanf("%d",&exp_data);
	 append1(head1,coe_data,exp_data);
	 n1--;
   }
   printf("Enter coefficients and Exponents of second polynomial.... \n");
   printf("Press any to continue....\n");
   getch();
   while(n2+1)
   {
	 printf("Enter the coefficient:- ");
	 scanf("%d",&coe_data);
	 printf("Enter the exponent:- ");
	 scanf("%d",&exp_data);
	 append2(head2,coe_data,exp_data);
	 n2--;
   }
   mul_two_polynomial(head1,head2);
   printf("Press any key to continue....\n");
   getch();
   display(head3);
}

