#include<stdio.h>
#include<stdlib.h>
void printarray(int a[],int n)
{
  int i;
  for(i=0;i<n;i++)
  {
    printf("Enter %d number Element:- ",i+1);
   scanf("%d",&a[i]);
  }
}
int binary_search(int a[],int key,int n)
{
  int low=0;
  int high=n-1;
  int mid;
  while(low<=high)
  {
    mid=(high+low)/2;
    if(key>a[mid])
    {
      low=mid+1;
	}
	else if(key<a[mid])
	{
	  high=mid-1;
	}
	else if(key==a[mid]) 
	{
	  printf("Element Is Found ||\n");
	  printf("%d Is %d Number Element ||\n",key,mid+1);
	  break;
	}
  }
  if(low>high)
  {
    printf("Element Is Not Present ||");
  }
}
int main()
{
  int mid,high,low,search,n,x;
  printf("Enter The Elements Number:- ");
  scanf("%d",&n);
  int a[n];
  printf("Enter The Elements:-\n");
  printarray(a,n);
  while(1)
  {
      printf("Enter The Search Element:- ");
      scanf("%d",&search);
      binary_search(a,search,n);
	  printf("\nPress 1 For Search Again ||");
	  printf("\nPress 0 For Exit ||\n");
	  scanf("%d",&x);
	  if(x==0)
	    exit(0);
  }
}
