#include<stdio.h>
#include<stdlib.h>
struct node
{
  int row;
  int col;
  int data;
  struct node* next;
};
struct node* head = NULL;
void create_link(int row_index,int col_index,int value)
{
  struct node* new_node = NULL;
  if(head == NULL)
  {
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->row = row_index;
	new_node->col = col_index;
	new_node->data = value;
	new_node->next = NULL;
	head = new_node;
  }
  else
  {
	struct node* p = head;
	while(p->next!=NULL)
	{
	  p = p->next;
	}
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->row = row_index;
	new_node->col = col_index;
	new_node->data = value;
	new_node->next = NULL;
	p->next = new_node;
  }
}
void print_optimize_matrix()
{
  struct node* p = head;
  printf("Row    =");
  while(p!=NULL)
  {
	printf("%d\t",p->row);
	p = p->next;
  }
  printf("\n");
  printf("column =");
  struct node* q = head;
  while(q!=NULL)
  {
	printf("%d\t",q->col);
	q = q->next;
  }
  printf("\n");
  printf("values =");
  struct node* r = head;
  while(r!=NULL)
  {
	printf("%d\t",r->data);
	r = r->next;
  }
}
int main()
{
  int row,col,i,j;
  printf("Enter row number of the matrix:- ");
  scanf("%d",&row);
  printf("Enter col number of the matrix:- ");
  scanf("%d",&col);
  int matrix[row][col];
  printf("Enter values of the matrix..\n");
  for(i=0;i<row;i++)
  {
	for(j=0;j<col;j++)
	{
	  scanf("%d",&matrix[i][j]);
	}
  }
  for(i=0;i<row;i++)
  {
	for(j=0;j<col;j++)
	{
	  if(matrix[i][j]!=0)
	  {
		create_link(i,j,matrix[i][j]);
	  }
	}
  }
  print_optimize_matrix();
}








