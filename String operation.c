#include<stdio.h>
#include<stdlib.h>
int length(char[]);
char* revers(char*);
int compare(char[]);
void str_cat(char[]);
void str_cpy(char[]);
int main()
{
  int size,i,n;
  printf("Enter the size for the string:- ");
  scanf("%d",&size);
  char string[size];
  printf("Enter the string:- ");
  scanf("%s",string);
  while(1)
  {
	  printf("\n-------------Your Options----------------\n");
	  printf("1: for Count the length of the string\n");
	  printf("2: for revers the string\n");
	  printf("3: for compare with another string\n");
	  printf("4: for concatenate the string with another string\n");
	  printf("5: for copy the main string into another string\n");
	  printf("6: for exit\n");
	  scanf("%d",&n);
	  switch (n)
	  {
		case 1:
		{
		  printf("The length of the string is:- %d\n",length(string));
		  break;
		}
		
		case 2:
		{
		  printf("%s",revers(string));
		  break;
		}
		case 3:
		{
		  int result=compare(string);
		  printf("%d",result);
		  break;
		}
		case 4:
		{
		  str_cat(string);
		  break;
		}
		case 5:
		{
		  str_cpy(string);
		  break;
		}
		case 6:
		{
		  exit(0);
		}
	  }
  }
  
}
int length(char str[])
{
   int i =  0,size = 0;
   while(str[i]!='\0')
   {
	  size++;
	  i++;
   }
   return size;
}
char* revers (char* str)
{
  int len = length(str),i,n = 0;
  char temp;
  for(i=0;i<len/2;i++)
  {
	 temp = str[i];
	 str[i] = str[len-1-i];
	 str[len-1-i] = temp;
  }
  return str;
}
int compare(char str[])
{
	char str_com[20];
	printf("Enter the string:- ");
	scanf("%s",str_com);
	int len = length(str_com),count = 0,i;
	for(i=0;i<len;i++)
	{
		if(str[i]>str_com[i])
		{
		  return 1;
		}
	    else if(str_com[i]>str[i])
	    {
		   return -1;
	    }
	    else if(str[i]==str_com[i])
	    {
		   count++;
		}
	}
	if(count==len)
	{
	  return 0;
	}
}
void str_cat(char str[])
{
  int size1,size2,i,count = 0;
  printf("Enter the size of the second string:- ");
  scanf("%d",&size2);
  char str1[size2];
  size1=length(str);
  printf("Enter the second string:- ");
  scanf("%s",str1);
  for(i=size1;str1[i-size1]!='\0';i++)
  {
	str[i] = str1[i-size1];
  }
  printf("%s",str);
}
void str_cpy(char str[])
{
   int size,i,key;
   printf("Enter the size of the another string:- ");
   scanf("%s",&size);
   char str1[size];
   for(i=0;str[i]!='\0';i++)
   {
	  str1[i]=str[i];
   }
   printf("\nString is copied into str1\n");
   printf("Press 1 for print str1 string\n");
   scanf("%d",&key);
   if(key==1)
   {
	 printf("str1 = %s",str1);
   }
}
