#include<stdio.h>
int main()
{
  printf("Enter Values for First Matrix:\n");
  int a[3][3],b[3][3],c[3][3],row,col,sum,k;
  for(row=0;row<3;row++)
  {
    for(col=0;col<3;col++)
    {
      printf("Enter value of a[%d][%d]:-",row,col);
      scanf("%d",&a[row][col]);
	}
  }
  printf("\n------------------------- first Matrix Is----------------------------\n");
  for(row=0;row<3;row++)
  {
    for(col=0;col<3;col++)
    {
      printf("%d\t",a[row][col]);
	}
	printf("\n");
  }
  printf("Enter vlaues for Second Matrix:\n");
  for(row=0;row<3;row++)
  {
    for(col=0;col<3;col++)
    {
      printf("Enter Value of b[%d][%d]:-",row,col);
      scanf("%d",&b[row][col]);
	}
  }
  printf("\n--------------------------Second Matrix is------------------------------\n");
  for(row=0;row<3;row++)
  {
    for(col=0;col<3;col++)
    {
      printf("%d\t",b[row][col]);
	}
	printf("\n");
  }
  for(row=0;row<3;row++)
  {
    for(col=0;col<3;col++)
    {
    sum=0;
      for(k=0;k<3;k++)
      {
         sum=sum+a[row][k]*b[k][col];
         c[row][col]=sum;
	  }
	}
  }
  printf("\n---------------------------Multiplication of Two Matrix-------------------------\n\n");
  for(row=0;row<3;row++)
  {
    for(col=0;col<3;col++)
    {
      printf("%d\t",c[row][col]);
	}
	printf("\n");
  }
  return 0;
}
