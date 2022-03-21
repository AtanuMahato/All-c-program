#include<stdio.h>
void printarray(int a[],int n)
{
  int i;
  for(i=0;i<n;i++)
  {
    printf("%d ",a[i]);
  }
}
void quicksort(int a[],int low,int high)
{
  int pertitionindex;
  if(low<high)
  {
    pertitionindex=pertition(a,low,high);
    quicksort(a,low,pertitionindex-1);
    quicksort(a,pertitionindex+1,high);
  }
}
int pertition(int a[],int low,int high)
{
  int swap;
  int pivot=a[low];
  int i=low+1;
  int j=high;
  do
  {
      while(a[i]<pivot)
        i++;
      while(a[j]>pivot)
        j--;
      if(i<j)
       {
         swap=a[i];
         a[i]=a[j];
         a[j]=swap;
       }  
  }
  while(i<j);
    swap=a[low];
    a[low]=a[j];
    a[j]=swap;
    return j;
}
int main()
{
  int n,i,l,h;
  printf("Enter The Elements Number Of The Array:- ");
  scanf("%d",&n);
  int a[n];
  l=0;h=n-1;
  printf("Enter Elements For The Array:- \n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  printf("Before Sorting The Array Is:- ");
  printarray(a,n);
  quicksort(a,l,h);
  printf("\nBefore Sorting The Array Is:- ");
  printarray(a,n);
}
