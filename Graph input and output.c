#include<stdio.h>
int main()
{
  int row,col,i,j;
  printf("Enter row number of adjacent matrix of the graph :- ");
  scanf("%d",&row);
  printf("Enter column number of adjacent matrix of the graph :- ");
  scanf("%d",&col);
  int adj_matrix[row][col];
  printf("Enter values of adjacent matrix....\n\n");
  for(i=0;i<row;i++)
  {
	for(j=0;j<col;j++)
	{
	   printf("Enter value of  [%d][%d] :- ",i,j);
	   scanf("%d",&adj_matrix[i][j]);
	}
  }
  printf("Grahp is ....\n");
  for(i=0;i<row;i++)
  {
	printf("%d ",i);
	for(j=0;j<col;j++)
	{
	  if(adj_matrix[i][j]!=0)
	  {
		printf("---->%d",j);
	  }
	}
	printf("\n");
  }
}
