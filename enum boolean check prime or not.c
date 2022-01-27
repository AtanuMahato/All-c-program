#include<stdio.h>
enum boolean
{
  true,false
};
typedef enum boolean ebol;
ebol check(int n)
{
  int i,k=0;
  for(i=2;i<=n/2;i++)
  {
    if(n%i==0)
    {
       k++;
	}
  }
     if(k==0)
        {
          return true;
        }
     else
        {
          return false;
        }
}
int main()
{
   int n;
   ebol result;
  printf("Enter a Possitive Number:-");
  scanf("%d",&n);
  result=check(n);
    if(result==true)
    {
      printf("%d is a Prime Number",n);
	}
	else
	{
	   printf("%d is Not a Prime Number",n);
	}
	return 0;
}
