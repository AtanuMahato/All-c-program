// Linear Search
#include<stdio.h>
#include<stdlib.h>
int main()
{
   int n,i,search,x,y;
   printf("Enter The Element Number:- ");
   scanf("%d",&n);
   int linear[n];
   printf("Enter 5 Elements  \n");
   for(i=0;i<n;i++)
   {
     scanf("%d",&linear[i]);
   }
   while(1)
   {
     printf("\nEnter THe Search Element:- ");
     scanf("%d",&search);
     for(i=0;i<n;i++)
      {
        if(linear[i]==search)
         {
           printf("Element Is Found ||");
           printf("\nElement Is In Position %d",i+1);
           break;
	     }
      }
      if(i==n)
       {
         printf("Element Is Not Present In ");
       }
       printf("\nEnter 1 For Search Another Element ||\n");
       printf("Enter 0 For Exit");
       scanf("%d",&x);
       if(x==0)
       exit(0);
   } 
}
