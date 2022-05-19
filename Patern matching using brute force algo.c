#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int match_patern(char[],int,char[],int);
int main()
{
  int N = 1,pos;
  while(N)
  {
	 int size_st,size_pt;
	 printf("Enter the size of the string:- ");
	 scanf("%d",&size_st);
	 char str[size_st];
	 printf("Enter the string:- \n");
	 scanf("%s",str);
	 printf("Enter the size of pattern:- ");
	 scanf("%d",&size_pt);
	 char str_pt[size_pt];
	 printf("Enter the pattern:- ");
	 scanf("%s",str_pt);
	 pos=match_patern(str,size_st,str_pt,size_pt);
	 if(pos)
	 {
	   printf("Pattern found at %d index of the string\n",pos);
	 }
	 else
	 {
	   printf("Pattern not found in the string\n");
	 }
	 printf("1: for continue\nOr press any number for exit\n");
     scanf("%d",&N);
     if(N!=1)
     exit(0);
  }
}
int match_patern(char str[],int size_st,char str_pt[],int size_pt)
{
   int i,j;
   for(i=0;i<=size_st-size_pt;i++)
   {
	 for(j=0;j<size_pt;j++)
	 {
	   if(str[i+j]==str_pt[j])
	   {
		 if(j==size_pt-1)
	     return i+1;
	   }
	   else
	   {
		  break;
	   }
	 }
   }
   return 0;
}
