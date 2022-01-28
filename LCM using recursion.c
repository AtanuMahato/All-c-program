#include<stdio.h>
int lcm(int n1,int n2)
{
  static int count=1;
  if(count%n1==0&&count%n2==0)
  {
    return count;
  }
   count++;
   lcm(n1,n2);
    return count;
}
int main()
{
  int n1,n2;
  printf("Enter Two Possitive Integer:-");
  scanf("%d%d",&n1,&n2);
  printf("LCM of %d %d is:-%d",n1,n2,lcm(n1,n2));
  return 0;
}
