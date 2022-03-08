#include<stdio.h>
void selectionshort(int a[],int n)
{
  int i,j,temp,swap;
  for(i=0;i<n-1;i++)
  {
   temp=i;
   for(j=i+1;j<n;j++)
   {
     if(a[j]<a[temp])
     {
      temp=j;
	 }
   }
   swap=a[i];
   a[i]=a[temp];
   a[temp]=swap;
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
 printf("Enter The Elements:-\n");
 for(i=0;i<n;i++)
 {
   scanf("%d",&a[i]);
 }
 selectionshort(a,n);
 printf("The Shorted Elements :- ");
 printarray(a,n);
}
