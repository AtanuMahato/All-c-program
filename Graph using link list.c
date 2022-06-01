#include<stdio.h>
#include<stdlib.h>
int main()
{
  int i,j;
  struct node
  {
	int data;
	struct node* link;
  };
  struct node* new_node,* temp;
  int node_number;
  printf("Enter total number of node in the graph:- ");
  scanf("%d",&node_number);
  struct node* head[node_number];
  printf("Enter values of the matrix :- \n");
  for(i=0;i<node_number;i++)
  {
	printf("\nhead[%d]\n",i);
	for(j=0;j<node_number;j++)
	{
	   new_node = (struct node*)malloc(sizeof(struct node));
	   printf("\nEnter the value:- ");
	   scanf("%d",&new_node->data);
	   new_node->link = NULL;
	   if(j==0)
	   {
		  head[i] = new_node;
       }
       else
       {
		  temp->link = new_node;
	   }
	   temp = new_node;
	}
  }
  printf("Matrix is ......\n");
  for(i=0;i<node_number;i++)
  {
    temp = head[i];
	for(j=0;j<node_number;j++)
	{
		  printf("%d ",temp->data);
		  temp = temp->link;
	}
	printf("\n");
  }
  printf("graph is ....\n");
  for(i=0;i<node_number;i++)
  {
	printf("head[%d]",i);
	temp = head[i];
	for(j=0;j<node_number;j++)
	{
		  if(temp->data==1)
	      
		  printf("---->%d ",j);
		  temp = temp->link;
	}
	printf("\n");
  }
}
