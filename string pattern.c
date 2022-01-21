#include<stdio.h>
int main()
{
 char str[30];int l=0,i,j;
 printf("Enter a String:-");
 gets(str);
 while(str[l]>'\0')
 {
   l++;
 }
 for(i=0;i<l;i++)
 {
   for(j=0;j<=i;j++)
   {
    printf("%c",str[j]);
   }
   printf("\n");
 }
 return 0;
}
