#include<stdio.h>
void bubbleshort(int a[],int n)
{
  int i,j,count=0,temp;
  for(i=0;i<n-1;i++)
  {
    count =1;
    for(j=0;j<n-1-i;j++)
    {
      if(a[j]>a[j+1])
      {
        temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
        count=0;
	  }
	}
	if(count==1)
	{
	  return;
	}
  }
}
void printarray(int a[],int n)
{
  int i;
  for(i=0;i<n;i++)
  {
   printf("%d ",a[i]);
  }
}
int main()
{
  int n,i;
  printf("Enter The Element Number:- ");
  scanf("%d",&n);
  int a[n];
  printf("Enter The Element:- \n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  printf("The Elements Are:- ");
  printarray(a,n);
  bubbleshort(a,n);
  printf("\nThe Shorted Elements Are:- ");
  printarray(a,n);
}
