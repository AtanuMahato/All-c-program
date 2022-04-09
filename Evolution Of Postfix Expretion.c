// Evolution of Postfix Expretion 
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
void push(int);
int pop();
char stack[50];
int top = -1;
int ch;
int main()
{
    char postfix[50],ele;
    int n1,n2,ans,i;
    printf("Enter The Postfix Expretion:- ");
    scanf("%s",postfix);
    printf("\nPostfix Expretion Is:-%s ",postfix);
    i=0;
     while(i<strlen(postfix))
     {
      ele = postfix[i];
      if(isdigit(ele))
      {
        push(ele-48);
	  }
	  else
	  {
	    n1=pop();
	    n2=pop();
	      switch(ele)
	      {
	        case '*':
	        {
	           ans = n2*n1;
	           break;
			}
	        case '/':
	        {
	           ans = n2/n1;
	           break;
			}
	        case '+':
	        {
	            ans = n2+n1;
	            break;
			}
	        case '-':
	        {
	           ans = n2-n1;
	           break;
			} 
		  }
		push(ans);
	  }
      i++;
	 }
	 printf("\nThe Evolution Of The Postfix Expretion Is %d",pop());
}
void push(int ele)
{
 if(top == 49)
 {
  printf("\nStack Is Overflowed ");
 }
 else
 {
  top = top + 1;
  stack[top] = ele;
 }
}
int pop()
{
  if(top == -1)
  {
    printf("\nStack Is Underflowed ");
  }
  else
  {
    ch=stack[top];
    top =top - 1;
  }
return ch;
}

