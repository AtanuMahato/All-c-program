#include<stdio.h>
void printarray(int a[],int n)
{
 int i;
 for(i=0;i<n;i++)
  printf("%d ",a[i]);
}
void merge(int a[],int low,int mid,int high,int n)
{
  int i,j,k,b[n];
  i=low;
  j=mid+1;
  k=low;
  while(i<=mid&&j<=high)
  {
    if(a[i]<a[j])
    {
      b[k]=a[i];
      k++,i++;
	}
	else
	{
	  b[k]=a[j];
	  k++,j++;
	}
  }
  while(i<=mid)
  {
    b[k]=a[i];
    k++,i++;
  }
  while(j<=high)
  {
    b[k]=a[j];
    k++,j++;
  }
  for(i=low;i<=high;i++)
  a[i]=b[i];
  
}
void mergesort(int a[],int low,int high,int n)
{
  if(low<high)
  {
    int mid=(low+high)/2;
    mergesort(a,low,mid,n);
    mergesort(a,mid+1,high,n);
    merge(a,low,mid,high,n);
  }
}

int main()
{
 int n,i;
 printf("Enter Elements Number For The Array:- ");
 scanf("%d",&n);
 int a[n];
 int low=0,high=n-1;
 printf("Enter The Elements:- \n");
 for(i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }
 printf("Before Merging The Array Is:- ");
 printarray(a,n);
 mergesort(a,low,high,n);
 printf("\nAfter Merging The Array Is :- ");
 printarray(a,n);
}
