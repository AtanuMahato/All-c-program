#include<stdio.h>
#include<stdlib.h>
int main()
{
 int *ptr=NULL,i;
 ptr=(int*)calloc(5,sizeof(int));
 for(i=0;i<5;i++)
 {
  printf("Enter the value of *(ptr+%d) ",i);
  scanf("%d",(ptr+i));
 }
 for(i=0;i<5;i++)
 {
  printf("The value of *(ptr+%d): %d\n",i,*(ptr+i));
 }
 free(ptr);
 ptr=NULL;
 return 0;
}
