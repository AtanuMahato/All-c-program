 /*
   1+1/2!+1/3!......1/n!
 */
#include<stdio.h>
int fact(int i)
{
 if(i<=1)
 {
    return 1;
 }
 else
 {
   return i*fact(i-1);
 }
 
 }
int main()
{
  int n,i,sum=0,a=2;
  printf("Enter a Possitive Integer Number:-");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
    sum=sum+(a/fact(i));
  }
  
  printf("Factorial Series of %d is:- %d",n,sum);
  return 0;
}
