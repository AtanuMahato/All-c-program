#include<stdio.h>
int add(int row,int col,int matrix[row][col] )
{
   int sum = 0,i,j;
   for(i=0;i<row;i++)
  {
	for(j=0;j<col;j++)
	{
	  if(i==j)
	  {
		sum = sum+matrix[i][j];
	  }
	}
  }
  return sum;
}
void print_matrix(int row,int col,int matrix[row][col])
{
  int i,j;
  for(i=0;i<row;i++)
  {
	for(j=0;j<col;j++)
	{
	  printf("%d\t",matrix[i][j]);
	}
	printf("\n");
  }
}
int main()
{
  int row,col,i,j,sum =0;
  printf("Enter the row number of the square matrix:- ");
  scanf("%d",&row);
  printf("Enter the column number of the square matrix:- ");
  scanf("%d",&col);
  int matrix[row][col];
  printf("Enter values for the square matrix.....\n\n");
  for(i=0;i<row;i++)
  {
	for(j=0;j<col;j++)
	{
	  printf("Enter [%d][%d] index value of the squar matrix:- ",i,j);
	  scanf("%d",&matrix[i][j]);
	}
  }
  printf("\nYour square is....\n");
  print_matrix(row,col,matrix);
  int result = add(row,col,matrix);
  printf("Trace of the square matrix is:- %d",result);
}

