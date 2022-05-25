#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdbool.h>
#define MIN 500
int main()
{
   int row,col,i,j,k = 0,x,y;
   printf("Enter row number of the adjacency matrix of the graph :- ");
   scanf("%d",&row);
   printf("Enter colimn number of the adjacency matrix of the graph :- ");
   scanf("%d",&col);
   int adj_matrix[row][col];
   printf("Enter the adjacency matrix....\n");
   for(i=0;i<row;i++)
   {
	 for(j=0;j<col;j++)
	 {
	   printf("Enter value of [%d][%d]",i,j);
	   scanf("%d",&adj_matrix[i][j]);
	 }
   }
	int selected[row];
	memset(selected,false,sizeof(selected));
	selected[0] = true;
	printf("Edges  :   Weight\n");
	while(k<row-1)
	{
	  int min = MIN;
	  for(i=0;i<row;i++)
	  {
	    if(selected[i])
	    {
		   for(j=0;j<col;j++)
		   {
			 if(!selected[j]&&adj_matrix[i][j])
			 {
			   if(min>adj_matrix[i][j])
			   {
				 min = adj_matrix[i][j];
				 x = i;
				 y = j;
			   }
			 }
		   }
	    }
	  }
	  printf("%d--%d    :   %d\n",x,y,adj_matrix[x][y]);
	  selected[y] = true;
	  k++;
	}
}
