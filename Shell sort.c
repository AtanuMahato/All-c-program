#include<stdio.h>
void print_array(int array[],int n)
{
  int i;
  for(i=0;i<n;i++)
  {
	printf("%d\t",array[i]);
  }
}
void shell_sort(int a[],int n)
{
  int i,j,k,swap;
  for(i=n/2;i>=1;i=i/2)
  {
	for(j=i;j<n;j++)
	{
	  for(k=j;k>=0;k=k-i)
	  {
		if(a[k+i]<a[k])
		{
		  swap = a[k+i];
		  a[k+i] = a[k];
		  a[k] = swap;
		}
		else
		{
		  break;
		}
	  }
	}
  }
}
int main()
{
  int n,i,j;
  printf("Enter the element number:- ");
  scanf("%d",&n);
  int array[n];
  printf("Enter the elements in unsorted order:- \n");
  for(i=0;i<n;i++)
  {
	 scanf("%d",&array[i]);
  }
  printf("Before sotring the elements are:- ");
  print_array(array,n);
  printf("\nAfter sorting the elements are:- ");
  shell_sort(array,n);
  print_array(array,n);
}
