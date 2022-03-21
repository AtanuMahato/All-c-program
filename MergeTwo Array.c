#include<stdio.h>
void printarray(int A[],int N)
{
  int i;
  for(i=0;i<N;i++)
   printf("%d ",A[i]);
}
void merge(int a[],int b[],int n1,int n2)
{
  int i,j,k,c[n1+n2];
  i=j=k=0;
  while(i<n1&&j<n2)
  {
    if(a[i]<b[j])
    {
      c[k]=a[i];
      k++,i++;
	}
	else
	{
	  c[k]=b[j];
	  k++,j++;
	}
  }
  while(i<n1)
  {
    c[k]=a[i];
    i++,k++;
  }
  while(j<n2)
  {
    c[k]=b[j];
    j++,k++;
  }
  printf("\nAfter Merging The Array Is :- ");
  printarray(c,(n1+n2));
}
int main()
{
  int n1,n2;
  printf("Enter Elements Number For First Array:- ");
  scanf("%d",&n1);
  printf("Enter Elements Number For Second Array:- ");
  scanf("%d",&n2);
  int a[n1],b[n2];
  printf("Enter Sorted Elements For First Array:-\n");
  int i;
  for(i=0;i<n1;i++)
   scanf("%d",&a[i]);
   printf("Enter Sorted Elements For Second Array:-\n");
    for(i=0;i<n2;i++)
     scanf("%d",&b[i]);
   printf("First Array :- ");
   printarray(a,n1);
   printf("\nSecond Array:- ");
   printarray(b,n2);
   merge(a,b,n1,n2);
}
