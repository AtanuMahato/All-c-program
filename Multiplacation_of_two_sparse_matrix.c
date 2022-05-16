#include<stdio.h>
#include<stdlib.h>
struct node
{
  int row;
  int col;
  int data;
  struct node* next;
};
struct node* head_1 = NULL;
struct node* head_2 = NULL;
struct node* head_3 = NULL;
void link_matrix_1(int row_index,int col_index,int  value)
{
  struct node* new_node = NULL;
  if(head_1 == NULL)
  {
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->row = row_index;
	new_node->col = col_index;
	new_node->data = value;
	new_node->next = NULL;
	head_1 = new_node;
  }
  else
  {
	struct node* p = head_1;
	new_node = (struct node*)malloc(sizeof(struct node));
	while(p->next!=NULL)
	{
	  p = p->next;
	}
	new_node->row = row_index;
	new_node->col = col_index;
	new_node->data = value;
	new_node->next = NULL;
	p->next = new_node;
  }
}
void print_optimize_matrix_1()
{
  struct node* p = head_1;
  printf("Row    =\t");
  while(p!=NULL)
  {
	printf("%d\t",p->row);
	p = p->next;
  }
  printf("\n");
  struct node* q = head_1;
  printf("Column =\t");
  while(q!=NULL)
  {
	printf("%d\t",q->col);
	q = q->next;
  }
  printf("\n");
  struct node* r = head_1;
  printf("values =\t");
  while(r!=NULL)
  {
	printf("%d\t",r->data);
	r =r->next;
  }
  printf("\n");
}
void link_matrix_2(int row_index,int col_index,int value)
{
  struct node* new_node = NULL;
  if(head_2 == NULL)
  {
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->row = row_index;
	new_node->col = col_index;
	new_node->data = value;
	new_node->next = NULL;
	head_2 = new_node;
  }
  else
  {
	struct node* p = head_2;
	new_node = (struct node*)malloc(sizeof(struct node));
	while(p->next!=NULL)
	{
	  p = p->next;
	}
	new_node->row = row_index;
	new_node->col = col_index;
	new_node->data = value;
	new_node->next = NULL;
	p->next = new_node;
  }
}
void print_optimize_matrix_2()
{
  struct node* p = head_2;
  printf("Row    =\t");
  while(p!=NULL)
  {
	printf("%d\t",p->row);
	p = p->next;
  }
  printf("\n");
  struct node* q = head_2;
  printf("Column =\t");
  while(q!=NULL)
  {
	printf("%d\t",q->col);
	q = q->next;
  }
  printf("\n");
  struct node* r = head_2;
  printf("values =\t");
  while(r!=NULL)
  {
	printf("%d\t",r->data);
	r =r->next;
  }
  printf("\n");
}
void multiply_matrix(int row_1,int col_1,int row_2,int col_2,int sparse_matrix_1[row_1][col_1],int sparse_matrix_2[row_2][col_2],int matrix_multiply[row_1][col_2])
{
   int i,j,k,sum;
   for(i=0;i<row_1;i++)
   {
	 for(j=0;j<col_2;j++)
	 {
	   sum = 0;
	   for(k=0;k<col_1;k++)
	   {
		 sum = sum + (sparse_matrix_1[i][k] * sparse_matrix_2[k][j]);
		 matrix_multiply[i][j] = sum;
	   }
	 }
   }
}
void link_matrix_multiply(int row_index,int col_index,int value)
{
   struct node* new_node = NULL;
  if(head_3 == NULL)
  {
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->row = row_index;
	new_node->col = col_index;
	new_node->data = value;
	new_node->next = NULL;
	head_3 = new_node;
  }
  else
  {
	struct node* p = head_3;
	new_node = (struct node*)malloc(sizeof(struct node));
	while(p->next!=NULL)
	{
	  p = p->next;
	}
	new_node->row = row_index;
	new_node->col = col_index;
	new_node->data = value;
	new_node->next = NULL;
	p->next = new_node;
  }
}
void print_matrix_mulriply()
{
  struct node* p = head_3;
  printf("Row    =\t");
  while(p!=NULL)
  {
	printf("%d\t",p->row);
	p = p->next;
  }
  printf("\n");
  struct node* q = head_3;
  printf("Column =\t");
  while(q!=NULL)
  {
	printf("%d\t",q->col);
	q = q->next;
  }
  printf("\n");
  struct node* r = head_3;
  printf("values =\t");
  while(r!=NULL)
  {
	printf("%d\t",r->data);
	r =r->next;
  }
  printf("\n");
}
int main()
{
  int row_1,col_1,i,j,row_2,col_2,n=1;
  while(n)
  {
    printf("Enter row number of the first sparse matrix:- ");
    scanf("%d",&row_1);
    printf("Enter column number of the first sparse matrix:- ");
    scanf("%d",&col_1);
    printf("Enter row number of the second sparse matrix:- ");
    scanf("%d",&row_2);
    printf("Enter column number of the second sparse matrix:- ");
    scanf("%d",&col_2);
    if(col_1 != row_2)
    {
	  printf("\nMultiplication no posiable for these order matrix\npress '1' for enter row and column for two matrix\nOr press '0'for exit");
	  scanf("%d",&n);
    }
    else
    {
	  int sparse_matrix_1[row_1][col_1],sparse_matrix_2[row_2][col_2],matrix_multiply[row_1][col_2];
	  printf("Enter values for the first sparse matrix...\n");
	  for(i=0;i<row_1;i++)
	  {
		for(j=0;j<col_1;j++)
		{
		  printf("Enter value of [%d][%d] index:- ",i,j);
		  scanf("%d",&sparse_matrix_1[i][j]);
		}
	  }
	  printf("\nFirst sparse matrix is.....\n");
	  for(i=0;i<row_1;i++)
	  {
		for(j=0;j<col_1;j++)
		{
		  if(sparse_matrix_1[i][j] != 0)
		  {
			link_matrix_1(i,j,sparse_matrix_1[i][j]);
		  }
		}
	  }
	  print_optimize_matrix_1();
	  printf("Enter values of second sparse matrix...\n");
	  for(i=0;i<row_2;i++)
	  {
		for(j=0;j<col_2;j++)
		{
		  printf("Enter value of [%d][%d] index:- ",i,j);
		  scanf("%d",&sparse_matrix_2[i][j]);
		}
	  }
	  printf("\nSecond spares matrix is....\n");
	  for(i=0;i<row_2;i++)
	  {
		for(j=0;j<col_2;j++)
		{
		  if(sparse_matrix_2[i][j]!=0)
		  {
			link_matrix_2(i,j,sparse_matrix_2[i][j]);
		  }
		}
	  }
	  print_optimize_matrix_2();
	  multiply_matrix(row_1,col_1,row_2,col_2,sparse_matrix_1,sparse_matrix_2,matrix_multiply);
	  printf("Multiplication of two sparse matrix is...\n");
	  for(i=0;i<row_1;i++)
	  {
		for(j=0;j<col_2;j++)
		{
		  if(matrix_multiply[i][j]!=0)
		  {
			link_matrix_multiply(i,j,matrix_multiply[i][j]);
		  }
		}
	  }
	  print_matrix_mulriply();
	  exit(0);
	}
  }
}
