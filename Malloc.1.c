#include<stdio.h>
#include<stdlib.h>
int main()
{
 int *ptr=NULL;
 ptr=(int*)calloc(5,sizeof(int));
  *(ptr+0)=10;
  *(ptr+1)=20;
  *(ptr+2)=30;
  *(ptr+3)=40;
  *(ptr+4)=50;
  printf("The value of *(ptr+0): %d\n",*(ptr+0));
  printf("The value of *(ptr+1): %d\n",*(ptr+1));
  printf("The value of *(ptr+2): %d\n",*(ptr+2));
  printf("The value of *(ptr+3): %d\n",*(ptr+3));
  printf("The value of *(ptr+4): %d\n",*(ptr+4));
 free(ptr);
 ptr=NULL;
 return 0;
}
