#include<stdio.h>
#include<conio.h>
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
void trans_matrix(int row,int col,int matrix[row][col],int matrix1[row][col])
{
  int i,j;
  for(i=0;i<row;i++)
  {
	for(j=0;j<col;j++)
	{
	   matrix1[i][j] = matrix[j][i];
	}
  }
}
int check_symmetric(int row,int col,int matrix[row][col],int matrix1[row][col])
{
   int count = 0,i,j;
   for(i=0;i<row;i++)
   {
	 for(j=0;j<col;j++)
	 {
		if(matrix[i][j] != matrix1[i][j])
		{
			count = 1;
			return count;
		}
	 }
   }
   return count;
}
int main()
{
  int row,col,i,j;
  printf("Enter row number of the square matrix:- ");
  scanf("%d",&row);
  printf("Enter column number of the square matrix:- ");
  scanf("%d",&col);
  int matrix[row][col];
  int matrix1[row][col];
  printf("Enter values for the square matrix.....\n\n");
  for(i=0;i<row;i++)
  {
	for(j=0;j<col;j++)
	{
	  printf("Enter [%d][%d] index value of the square matrix:- ",i,j);
	  scanf("%d",&matrix[i][j]);
	}
  }
  printf("Your square matrix...\n");
  print_matrix(row,col,matrix);
  trans_matrix(row,col,matrix,matrix1);
  int result = check_symmetric(row,col,matrix,matrix1);
  printf("\nPress any key to check the square matrix is symmetric or not\n");
  getch();
  if(result == 0)
  {
	printf("Square matrix is symmetric");
  }
  else
  {
	printf("Square matrix is not symmetric");
  }
}
