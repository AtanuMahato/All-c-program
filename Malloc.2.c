#include<stdio.h>
#include<stdlib.h>
int main()
{
  int* ptr=NULL;
  int i,n;
  printf("Enter Value of n:-");
  scanf("%d",&n);
  ptr=(int*)malloc(n*sizeof(int));
   for(i=0;i<n;i++)
   {
     printf("Enter Value of *(ptr+%d):-",i);
     scanf("%d",(ptr+i));
   }
   for(i=0;i<n;i++)
   {
     printf("Value of *(ptr+%d):-%d\n",i,*(ptr+i));
   }
   free(ptr);
   ptr=NULL;
}
