#include<stdio.h>
#include<conio.h>
int main()
{
  int row,col,i,j,max;
  printf("Enter row number:- ");
  scanf("%d",&row);
  printf("Enter column number:- ");
  scanf("%d",&col);
  int matrix[row][col];
  for(i=0;i<row;i++)
  {
	for(j=0;j<col;j++)
	{
	  printf("Enter [%d][%d] index value of the matrix:- ",i,j);
	  scanf("%d",&matrix[i][j]);
	}
  }
  printf("your metrix is....\n");
  for(i=0;i<row;i++)
  {
	for(j=0;j<col;j++)
	{
	  printf("%d\t",matrix[i][j]);
	}
	printf("\n");
  }
  max = matrix[0][0];
  for(i=0;i<row;i++)
  {
	for(j=0;j<col;j++)
	{
	  if(max<matrix[i][j])
	  {
		max = matrix[i][j];
	  }
	}
  }
  printf("\nPress any key to print the maximum element of the matrix.. ");
  getch();
  printf("\nmaximum elementin the matrix = %d",max);
}
