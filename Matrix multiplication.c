#include<stdio.h>
int main()
{
	int a[3][3],b[3][3],row,col,sum,k,c[3][3];
     for(row=0;row<3;row++)
     {
     	for(col=0;col<3;col++)
     	{
     		printf("Enter value of a[%d][%d]=",row,col);
     		scanf("%d",&a[row][col]);
		}
	 }
     for(row=0;row<3;row++)
     {
     	for(col=0;col<3;col++)
     	{
     		printf("Enter value of b[%d][%d]=",row,col);
     		scanf("%d",&b[row][col]);
		}
	 }
	  for(row=0;row<3;row++)
     {
     	for(col=0;col<3;col++)
     	{
     		sum=0;
	      for(k=0;k<3;k++)
	       {
	 	     sum=sum+(a[row][k]*b[k][col]);
	 	     c[row][col]=sum;
	       }
	   }
     }
     printf("Multipliction of two matrix =\n");
	 for(row=0;row<3;row++)
	 {
	 	for(col=0;col<3;col++)
	 	{
	 		printf("%d ",c[row][col]);
		}
		printf("\n");
	 }
}
