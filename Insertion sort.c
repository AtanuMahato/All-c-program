#include<stdio.h>
int main()
{
  int n,i,j,temp;
  printf("Enter The Element Number:- ");
  scanf("%d",&n);
  int array[n];
  printf("Enter %d Elements:- \n",n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&array[i]);
  }
  for(i=1;i<n;i++)
  {
    array[i]==temp;
    j=i-1;
    while((temp<array[j])&&(j>=0))
    {
      array[j+1]=array[j];
      j=j-1;
	}
	array[j+1]=temp;
  }
  printf("Shorted Array Is:- ");
  for(i=0;i<n;i++)
  {
    printf("%d ",array[i]);
  }
}
